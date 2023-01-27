bin/dexterity.lib: bin/dexterity.o
	ar crf lib/dexterity.lib bin/dexterity.o

bin/dexterity.o: src/dexterity.cpp
	g++ -o bin/dexterity.o -c src/dexterity.cpp