SOURCECLIENT = Client.cpp ClientVectorCheck.cpp
OBJSCLIENT = Client.o ClientVectorCheck.o
HEADERCLIENT = ClientVectorCheck.h
OBJS	= Server.o Distance.o EuclideanDistance.o TaxicabGeometry.o MinkowskiDistance.o CanberraDistance.o ChebyshevDistance.o VectorCheck.o SelectSort.o Database.o RecieveCheckServer.o OpenFile.o
SOURCE	= Server.cpp distance/Distance.cpp distance/EuclideanDistance.cpp distance/TaxicabGeometry.cpp distance/MinkowskiDistance.cpp distance/CanberraDistance.cpp distance/ChebyshevDistance.cpp VectorCheck.cpp SelectSort.cpp Database.cpp RecieveCheckServer.cpp OpenFile.cpp
HEADER	= distance/Distance.h distance/EuclideanDistance.h distance/TaxicabGeometry.h distance/MinkowskiDistance.h distance/CanberraDistance.h distance/ChebyshevDistance.h VectorCheck.h SelectSort.h Database.h RecieveCheckServer.h OpenFile.h
OUTS	= server.out
OUTC	= client.out
CC	= g++
FLAGS	= -g -c

all: $(OBJS) $(OBJSCLIENT)
	$(CC) -g $(OBJS) -o $(OUTS) $(LFLAGS)
	$(CC) -g $(OBJSCLIENT) -o $(OUTC) $(LFLAGS)

client.o: Client.cpp
	$(CC) $(FLAGS) Client.cpp -std=c++11

ClientVectorCheck.o: ClientVectorCheck.cpp 
	$(CC) $(FLAGS) ClientVectorCheck.cpp -std=c++11

Server.o: Server.cpp
	$(CC) $(FLAGS) Server.cpp -std=c++11

Distance.o: distance/Distance.cpp
	$(CC) $(FLAGS) distance/Distance.cpp -std=c++11

EuclideanDistance.o: distance/EuclideanDistance.cpp
	$(CC) $(FLAGS) distance/EuclideanDistance.cpp -std=c++11

TaxicabGeometry.o: distance/TaxicabGeometry.cpp
	$(CC) $(FLAGS) distance/TaxicabGeometry.cpp -std=c++11

MinkowskiDistance.o: distance/MinkowskiDistance.cpp
	$(CC) $(FLAGS) distance/MinkowskiDistance.cpp -std=c++11

CanberraDistance.o: distance/CanberraDistance.cpp
	$(CC) $(FLAGS) distance/CanberraDistance.cpp -std=c++11

ChebyshevDistance.o: distance/ChebyshevDistance.cpp
	$(CC) $(FLAGS) distance/ChebyshevDistance.cpp -std=c++11

VectorCheck.o: VectorCheck.cpp
	$(CC) $(FLAGS) VectorCheck.cpp -std=c++11

SelectSort.o: SelectSort.cpp
	$(CC) $(FLAGS) SelectSort.cpp -std=c++11

Database.o: Database.cpp
	$(CC) $(FLAGS) Database.cpp -std=c++11

RecieveCheckServer.o: RecieveCheckServer.cpp
	$(CC) $(FLAGS) RecieveCheckServer.cpp -std=c++11

OpenFile.o: OpenFile.cpp
	$(CC) $(FLAGS) OpenFile.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUTC) $(OUTS) $(OBJSCLIENT)
