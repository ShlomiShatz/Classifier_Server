SOURCECLIENT = Client/Client.cpp Client/ClientVectorCheck.cpp
OBJSCLIENT = Client.o ClientVectorCheck.o
HEADERCLIENT = Client/ClientVectorCheck.h
OBJS	= Server.o Distance.o EuclideanDistance.o TaxicabGeometry.o MinkowskiDistance.o CanberraDistance.o ChebyshevDistance.o VectorCheck.o SelectSort.o Database.o RecieveCheckServer.o OpenFile.o
SOURCE	= Server/Server.cpp Distances/Distance.cpp Distances/EuclideanDistance.cpp Distances/TaxicabGeometry.cpp Distances/MinkowskiDistance.cpp Distances/CanberraDistance.cpp Distances/ChebyshevDistance.cpp Server/VectorCheck.cpp Server/SelectSort.cpp Server/Database.cpp Server/RecieveCheckServer.cpp OpenFile.cpp
HEADER	= Distances/Distance.h Distances/EuclideanDistance.h Distances/TaxicabGeometry.h Distances/MinkowskiDistance.h Distances/CanberraDistance.h Distances/ChebyshevDistance.h Server/VectorCheck.h Server/SelectSort.h Server/Database.h Server/RecieveCheckServer.h OpenFile.h
OUTS	= server.out
OUTC	= client.out
CC	= g++
FLAGS	= -g -c -std=c++11

all: $(OBJS) $(OBJSCLIENT)
	$(CC) -g $(OBJS) -o $(OUTS) $(LFLAGS)
	$(CC) -g $(OBJSCLIENT) -o $(OUTC) $(LFLAGS)

Client.o: Client/Client.cpp
	$(CC) $(FLAGS) Client/Client.cpp

ClientVectorCheck.o: Client/ClientVectorCheck.cpp 
	$(CC) $(FLAGS) Client/ClientVectorCheck.cpp

Server.o: Server/Server.cpp
	$(CC) $(FLAGS) Server/Server.cpp

Distance.o: Distances/Distance.cpp
	$(CC) $(FLAGS) Distances/Distance.cpp

EuclideanDistance.o: Distances/EuclideanDistance.cpp
	$(CC) $(FLAGS) Distances/EuclideanDistance.cpp

TaxicabGeometry.o: Distances/TaxicabGeometry.cpp
	$(CC) $(FLAGS) Distances/TaxicabGeometry.cpp

MinkowskiDistance.o: Distances/MinkowskiDistance.cpp
	$(CC) $(FLAGS) Distances/MinkowskiDistance.cpp

CanberraDistance.o: Distances/CanberraDistance.cpp
	$(CC) $(FLAGS) Distances/CanberraDistance.cpp

ChebyshevDistance.o: Distances/ChebyshevDistance.cpp
	$(CC) $(FLAGS) Distances/ChebyshevDistance.cpp

VectorCheck.o: Server/VectorCheck.cpp
	$(CC) $(FLAGS) Server/VectorCheck.cpp

SelectSort.o: Server/SelectSort.cpp
	$(CC) $(FLAGS) Server/SelectSort.cpp

Database.o: Server/Database.cpp
	$(CC) $(FLAGS) Server/Database.cpp

RecieveCheckServer.o: Server/RecieveCheckServer.cpp
	$(CC) $(FLAGS) Server/RecieveCheckServer.cpp

OpenFile.o: OpenFile.cpp
	$(CC) $(FLAGS) OpenFile.cpp

clean:
	rm -f $(OBJS) $(OUTC) $(OUTS) $(OBJSCLIENT)
