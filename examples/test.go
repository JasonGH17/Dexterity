package main

import (
	"fmt"
	"github.com/JasonGH17/Dexterity"
)

func main() {
	PORT := 8000

	server := dexterity.Dexterity()

	server.Get("/", func() {
		fmt.Print("GET request on /")
	})

	server.Listen(PORT, func() {
		fmt.Printf("Dexterity listening on port %d", PORT)
	})
}