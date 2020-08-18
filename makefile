CC = g++
CFLAGS = -std=c++11

all: clientMain.cpp serverMain.cpp Server.o Client.o
	$(CC) $(CFLAGS) serverMain.cpp  Server.o -o chatroom_server
	$(CC) $(CFLAGS) clientMain.cpp Client.o -o chatroom_client

Server.o : server.cpp server.h common.h
	$(CC) $(CFLAGS) -c server.cpp

Client.o : client.cpp client.h common.h
	$(CC) $(CFLAGS) -c client.cpp

clean :
	rm -f *.o chatroom_server chatroom_client
