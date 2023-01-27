bin/dexterity.lib: bin/dexterity.o bin/tcp_server.o
	g++ -shared -o lib/dexterity.dll bin/dexterity.o bin/tcp_server.o -lWs2_32 -luser32

bin/dexterity.o: src/dexterity.cpp
	g++ -Wall -o bin/dexterity.o -c src/dexterity.cpp

bin/tcp_server.o: src/server/tcp_server_win32.cpp
	g++ -Wall -o bin/tcp_server.o -c src/server/tcp_server_win32.cpp