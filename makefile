SOURCECLIENT = Client/Client.cpp Client/ClientVectorCheck.cpp
OBJSCLIENT = Client.o ClientVectorCheck.o
HEADERCLIENT = Client/ClientVectorCheck.h
OBJS	= Server.o Distance.o EuclideanDistance.o TaxicabGeometry.o MinkowskiDistance.o CanberraDistance.o ChebyshevDistance.o VectorCheck.o SelectSort.o Database.o RecieveCheckServer.o OpenFile.o
SOURCE	= Server/Server.cpp Distances/Distance.cpp Distances/EuclideanDistance.cpp Distances/TaxicabGeometry.cpp Distances/MinkowskiDistance.cpp Distances/CanberraDistance.cpp Distances/ChebyshevDistance.cpp VectorCheck.cpp Server/SelectSort.cpp Server/Database.cpp Server/RecieveCheckServer.cpp OpenFile.cpp
HEADER	= Distances/Distance.h Distances/EuclideanDistance.h Distances/TaxicabGeometry.h Distances/MinkowskiDistance.h Distances/CanberraDistance.h Distances/ChebyshevDistance.h VectorCheck.h Server/SelectSort.h Server/Database.h Server/RecieveCheckServer.h OpenFile.h
OUTS	= server.out
OUTC	= client.out
CC	= g++
FLAGS	= -g -c

all: $(OBJS) $(OBJSCLIENT)
	$(CC) -g $(OBJS) -o $(OUTS) $(LFLAGS)
	$(CC) -g $(OBJSCLIENT) -o $(OUTC) $(LFLAGS)

client.o: Client/Client.cpp
	$(CC) $(FLAGS) Client/Client.cpp -std=c++11

ClientVectorCheck.o: Client/ClientVectorCheck.cpp 
	$(CC) $(FLAGS) Client/ClientVectorCheck.cpp -std=c++11

Server.o: Server/Server.cpp
	$(CC) $(FLAGS) Server/Server.cpp -std=c++11

Distance.o: Distances/Distance.cpp
	$(CC) $(FLAGS) Distances/Distance.cpp -std=c++11

EuclideanDistance.o: Distances/EuclideanDistance.cpp
	$(CC) $(FLAGS) Distances/EuclideanDistance.cpp -std=c++11

TaxicabGeometry.o: Distances/TaxicabGeometry.cpp
	$(CC) $(FLAGS) Distances/TaxicabGeometry.cpp -std=c++11

MinkowskiDistance.o: Distances/MinkowskiDistance.cpp
	$(CC) $(FLAGS) Distances/MinkowskiDistance.cpp -std=c++11

CanberraDistance.o: Distances/CanberraDistance.cpp
	$(CC) $(FLAGS) Distances/CanberraDistance.cpp -std=c++11

ChebyshevDistance.o: Distances/ChebyshevDistance.cpp
	$(CC) $(FLAGS) Distances/ChebyshevDistance.cpp -std=c++11

VectorCheck.o: VectorCheck.cpp
	$(CC) $(FLAGS) VectorCheck.cpp -std=c++11

SelectSort.o: Server/SelectSort.cpp
	$(CC) $(FLAGS) Server/SelectSort.cpp -std=c++11

Database.o: Server/Database.cpp
	$(CC) $(FLAGS) Server/Database.cpp -std=c++11

RecieveCheckServer.o: Server/RecieveCheckServer.cpp
	$(CC) $(FLAGS) Server/RecieveCheckServer.cpp -std=c++11

OpenFile.o: OpenFile.cpp
	$(CC) $(FLAGS) OpenFile.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUTC) $(OUTS) $(OBJSCLIENT)
