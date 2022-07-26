package main

import (
	"fmt"
	"github.com/JasonGH17/Dexterity"
)

func main() {
	PORT := 8000

	server := dexterity.Dexterity()

	server.Get("/test1", func() {
		fmt.Print("GET request on /test1\n")
	})
	server.Get("/test2", func() {
		fmt.Print("GET request on /test2\n")
	})

	server.Listen(PORT, func() {
		fmt.Printf("Dexterity listening on port %d", PORT)
	})
}