all: server client

server: myserver.cpp server.cpp packet/packets.cpp packet/type_serializers.cpp
	@echo "Compiling server..."
	g++ myserver.cpp server.cpp packet/packets.cpp packet/type_serializers.cpp -o myserver

client: myserver.cpp server.cpp packet/packets.cpp packet/type_serializers.cpp
	@echo "Compiling client..."
	g++ myclient.cpp client.cpp packet/packets.cpp packet/type_serializers.cpp -o myclient 

clean:
	@echo "Cleaning up..."
	rm -rvf myclient myserver *.o
