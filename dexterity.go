package dexterity

import (
	"fmt"
	"net/http"
)

type Request struct {
}
type Response struct {
}

type Handler struct {
	method   string
	path     string
	callback func()
}

type Server struct {
	server   *http.ServeMux
	handlers []Handler
}

func (server *Server) Listen(port int, callback func()) {
	server.server.HandleFunc("/", func(res http.ResponseWriter, req *http.Request) {
		for _, handler := range server.handlers {
			if req.URL.String() == handler.path && req.Method == handler.method {
				handler.callback()
			}
		}
	})

	http.ListenAndServe(fmt.Sprintf(":%d", port), server.server)

	callback()
}

func (server *Server) Get(path string, handler func()) {
	_handler := Handler{
		"GET",
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
