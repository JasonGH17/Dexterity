package main

import (
	"fmt"
	"github.com/JasonGH17/Dexterity"
)

func main() {
	PORT := 8000

	server := dexterity.Dexterity()

	server.Get("/test1", func(req dexterity.Request, res dexterity.Response) {
		fmt.Print("GET request on /test1\n")
		res.Send("Send test")
	})
	server.Get("/test2", func(req dexterity.Request, res dexterity.Response) {
		fmt.Print("GET request on /test2\n")
		res.SendFile("test.html")
	})

	server.Listen(PORT, func() {
		fmt.Printf("Dexterity listening on port %d", PORT)
	})
}