example1: bin/example1.exe
	cp ../lib/dexterity.dll bin/dexterity.dll
	cp ../lib/http_utils.lib bin/http_utils.lib
	./bin/example1.exe

bin/example1.exe: example1.cpp 
	g++ -g -o bin/example1.exe example1.cpp -L../lib -ldexterity -I../src