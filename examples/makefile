CC = g++
STD = -std=c++17
CFLAGS = -Wall -Werror -Wextra -pedantic -g 
INCLUDE = -I../src
LINK = -L../lib -ldexterity

ifeq ($(OS),Windows_NT)
	PROG = example1.exe
	LIB = dexterity.dll
	WL =
else 
	PROG = example1
	LIB = libdexterity.so
	WL = -Wl,-rpath=.
endif

example1: bin/$(PROG)
	cp ../lib/$(LIB) bin/$(LIB)

bin/$(PROG): example1.cpp 
	$(CC) $(STD) $(CFLAGS) -o bin/$(PROG) example1.cpp $(LINK) $(INCLUDE) $(WL)