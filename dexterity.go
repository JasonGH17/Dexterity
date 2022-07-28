package dexterity

import (
	"fmt"
	"net/http"
)

type Request struct {
	body   string
	params []string
}
type Response struct {
}

type Handler struct {
	method   string
	path     string
	callback func(Request, Response)
}

type Server struct {
	server   *http.ServeMux
	handlers []Handler
}

func (server *Server) Listen(port int, callback func()) {
	server.server.HandleFunc("/", func(res http.ResponseWriter, req *http.Request) {
		Dreq := Request{
			"body",
			[]string{""},
		}
		Dres := Response{}

		for _, handler := range server.handlers {
			if (req.URL.String() == handler.path && req.Method == handler.method) || handler.method == "MIDDLEWARE" {
				handler.callback(Dreq, Dres)
			}
		}
	})

	http.ListenAndServe(fmt.Sprintf(":%d", port), server.server)

	callback()
}

func (server *Server) Get(path string, handler func(req Request, res Response)) {
	_handler := Handler{
		"GET",
		path,
		handler,
	}

	server.handlers = append(server.handlers, _handler)
}
func (server *Server) POST(path string, handler func(Request, Response)) {
	_handler := Handler{
		"POST",
		path,
		handler,
	}

	server.handlers = append(server.handlers, _handler)
}

func Dexterity() Server {
	newServer := Server{
		http.NewServeMux(),
		[]Handler{},
	}

	return newServer
}
