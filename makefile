CC = g++
CFLAGS = -std=c++11

all: clientMain.cpp serverMain.cpp server.o client.o
	$(CC) $(CFLAGS) serverMain.cpp  server.o -o chatroom_server
	$(CC) $(CFLAGS) clientMain.cpp client.o -o chatroom_client

server.o : server.cpp server.h common.h
	$(CC) $(CFLAGS) -c server.cpp

client.o : client.cpp client.h common.h
	$(CC) $(CFLAGS) -c client.cpp

clean :
	rm -f *.o chatroom_server chatroom_client
