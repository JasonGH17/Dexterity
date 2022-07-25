package main

import "github.com/JasonGH17/Dexterity"

func main() {
	server := dexterity.Dexterity()

	server.Listen(8000)
}