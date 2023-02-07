bin/server: server.cpp
	g++ -std=c++17 -Wall -Werror -Wextra -pedantic -o bin/server server.cpp -Wl,-rpath=../../lib -L../../lib -ldexterity -I../../src 

test: bin/server
	./bin/server & time ./concurrent_requests.bash
	