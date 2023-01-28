bin/dexterity.dll: bin/dexterity.o bin/tcp_server.o bin/http_server.o
	g++ -shared -g -o lib/dexterity.dll bin/dexterity.o bin/tcp_server.o bin/http_server.o -lWs2_32 -luser32

bin/dexterity.o: src/dexterity.cpp
	g++ -Wall -g -o bin/dexterity.o -c src/dexterity.cpp

bin/tcp_server.o: src/server/tcp_server_win32.cpp
	g++ -Wall -g -o bin/tcp_server.o -c src/server/tcp_server_win32.cpp

bin/http_server.o: src/server/http_server.cpp
	g++ -Wall -g -o bin/http_server.o -c src/server/http_server.cpp