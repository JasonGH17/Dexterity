package dexterity

import (
	"fmt"
	"net/http"
)

type Server struct {
	server *http.ServeMux
}

func (server *Server) Listen(port int) {
	http.ListenAndServe(fmt.Sprintf(":%d", port), server.server)
}

func Dexterity() Server {
	newServer := Server{
		http.NewServeMux(),
	}

	return newServer
}
