SOURCECLIENT = Client.cpp ClientVectorCheck.cpp
OBJSCLIENT = Client.o ClientVectorCheck.o
HEADERCLIENT = ClientVectorCheck.h
OBJS	= Server.o Distance.o EuclideanDistance.o TaxicabGeometry.o MinkowskiDistance.o CanberraDistance.o ChebyshevDistance.o VectorCheck.o SelectSort.o Database.o RecieveCheckServer.o OpenFile.o
SOURCE	= Server.cpp Distance.cpp EuclideanDistance.cpp TaxicabGeometry.cpp MinkowskiDistance.cpp CanberraDistance.cpp ChebyshevDistance.cpp VectorCheck.cpp SelectSort.cpp Database.cpp RecieveCheckServer.cpp OpenFile.cpp
HEADER	= Distance.h EuclideanDistance.h TaxicabGeometry.h MinkowskiDistance.h CanberraDistance.h ChebyshevDistance.h VectorCheck.h SelectSort.h Database.h RecieveCheckServer.h OpenFile.h
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

Distance.o: Distance.cpp
	$(CC) $(FLAGS) Distance.cpp -std=c++11

EuclideanDistance.o: EuclideanDistance.cpp
	$(CC) $(FLAGS) EuclideanDistance.cpp -std=c++11

TaxicabGeometry.o: TaxicabGeometry.cpp
	$(CC) $(FLAGS) TaxicabGeometry.cpp -std=c++11

MinkowskiDistance.o: MinkowskiDistance.cpp
	$(CC) $(FLAGS) MinkowskiDistance.cpp -std=c++11

CanberraDistance.o: CanberraDistance.cpp
	$(CC) $(FLAGS) CanberraDistance.cpp -std=c++11

ChebyshevDistance.o: ChebyshevDistance.cpp
	$(CC) $(FLAGS) ChebyshevDistance.cpp -std=c++11

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
