all:
	gcc -I. -o build/server.o src/server.c
	gcc -I. -o build/client.o src/client.c
	
server: src/server.c include/server.h
	gcc -I. -o build/server.o src/server.c

client: src/client.c include/server.h
	gcc -I. -o build/client.o src/client.c

run-server: server
	./build/server.o
	
run-client: client
	./build/client.o
	
clean:
	rm build/*.o