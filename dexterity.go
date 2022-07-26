package dexterity

import (
	"fmt"
	"log"
	"net/http"
	"os"
	"path/filepath"
)

type Request struct {
	body   string
	params []string
}
type Response struct {
	rawRes http.ResponseWriter
}

func (res *Response) SendFile(path string) {
	filepath, err := filepath.Abs(path)
	file, _err := os.ReadFile(filepath)
	if err != nil && _err != nil {
		log.Printf("ERROR: %v", err)
	}

	res.rawRes.Write(file)
}

func (res *Response) Send(content string) {
	res.rawRes.Write([]byte(content))
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
		Dres := Response{res}

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
func (server *Server) Post(path string, handler func(Request, Response)) {
	_handler := Handler{
		"POST",
		path,
		handler,
	}

	server.handlers = append(server.handlers, _handler)
}

func (server *Server) Use(handler func(Request, Response)) {
	_handler := Handler{
		"MIDDLEWARE",
		"",
		handler,
	}

	server.handlers = append(server.handlers, _handler)
	fmt.Printf("%#v\n", server.handlers)
}

func Dexterity() Server {
	newServer := Server{
		http.NewServeMux(),
		[]Handler{},
	}

	return newServer
}
