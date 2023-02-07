CC = g++
STD = -std=c++17

ifeq ($(OS),Windows_NT)
CFLAGS = -Wall -Werror -Wextra -pedantic -g -shared
LINK = -lWs2_32 -luser32
else
CFLAGS = -Wall -Werror -Wextra -pedantic -g -shared -fPIC
LINK =
endif

ifeq ($(OS),Windows_NT)
bin/dexterity.dll: bin/dexterity.o bin/tcp_server_win32.o bin/http_controller.o bin/http_server.o
	$(CC) $(STD) $(CFLAGS) -o lib/dexterity.dll bin/dexterity.o bin/tcp_server_win32.o bin/http_controller.o bin/http_server.o $(LINK)
else
bin/libdexterity.so: bin/dexterity.o bin/tcp_server_linux.o bin/http_controller.o bin/http_server.o
	$(CC) $(STD) $(CFLAGS) -o lib/libdexterity.so bin/dexterity.o bin/tcp_server_linux.o bin/http_controller.o bin/http_server.o $(LINK)
endif

bin/dexterity.o: src/dexterity.cpp
	$(CC) $(STD) $(CFLAGS) -o bin/dexterity.o -c src/dexterity.cpp

bin/tcp_server_win32.o: src/server/tcp_server_win32.cpp
	$(CC) $(STD) $(CFLAGS) -o bin/tcp_server_win32.o -c src/server/tcp_server_win32.cpp

bin/tcp_server_linux.o: src/server/tcp_server_linux.cpp
	$(CC) $(STD) $(CFLAGS) -o bin/tcp_server_linux.o -c src/server/tcp_server_linux.cpp

bin/http_server.o: src/server/http_server.cpp src/server/util/http_request.h src/server/util/http_response.h src/server/util/http_header.h
	$(CC) $(STD) $(CFLAGS) -o bin/http_server.o -c src/server/http_server.cpp

bin/http_controller.o: src/server/http_controller.cpp
	$(CC) $(STD) $(CFLAGS) -o bin/http_controller.o -c src/server/http_controller.cpp