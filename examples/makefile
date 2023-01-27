example1: bin/example1.exe
	cp ../lib/dexterity.dll bin/dexterity.dll
	./bin/example1.exe

bin/example1.exe: example1.cpp 
	g++ -o bin/example1.exe example1.cpp -L../lib -ldexterity -I../src