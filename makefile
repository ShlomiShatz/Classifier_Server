SOURCECLIENT = Client/Client.cpp Client/ClientVectorCheck.cpp IOs/SocketIO.cpp IOs/StandartIO.cpp OpenFile.cpp
OBJSCLIENT = Client.o ClientVectorCheck.o SocketIO.o StandartIO.o OpenFile.o
HEADERCLIENT = Client/ClientVectorCheck.h IOs/SocketIO.h IOs/StandartIO.h OpenFile.h
OBJS	= Server.o Distance.o EuclideanDistance.o TaxicabGeometry.o MinkowskiDistance.o CanberraDistance.o ChebyshevDistance.o VectorCheck.o SelectSort.o Database.o RecieveCheckServer.o OpenFile.o CLI.o SocketIO.o UploadUnclassCommand.o AlgoSettingCommand.o ClassifyCommand.o DisplayResultsCommand.o DownloadResultsCommand.o DistanceMetrixDict.o ExitCommand.o CommandData.o
SOURCE	= Server/Server.cpp Distances/Distance.cpp Distances/EuclideanDistance.cpp Distances/TaxicabGeometry.cpp Distances/MinkowskiDistance.cpp Distances/CanberraDistance.cpp Distances/ChebyshevDistance.cpp Server/VectorCheck.cpp Server/SelectSort.cpp Server/Database.cpp Server/RecieveCheckServer.cpp OpenFile.cpp IOs/SocketIO.cpp Commands/CLI.cpp Commands/UploadUnclassCommand.cpp Commands/AlgoSettingCommand.cpp Commands/ClassifyCommand.cpp Commands/DisplayResultsCommand.cpp Commands/DownloadResultsCommand.cpp Commands/DistanceMetrixDict.cpp Commands/ExitCommand.cpp Commands/CommandData.cpp
HEADER	= Distances/Distance.h Distances/EuclideanDistance.h Distances/TaxicabGeometry.h Distances/MinkowskiDistance.h Distances/CanberraDistance.h Distances/ChebyshevDistance.h Server/VectorCheck.h Server/SelectSort.h Server/Database.h Server/RecieveCheckServer.h OpenFile.h IOs/SocketIO.h Commands/CLI.h Commands/UploadUnclassCommand.h Commands/AlgoSettingCommand.h Commands/ClassifyCommand.h Commands/DisplayResultsCommand.h Commands/DownloadResultsCommand.h Commands/DistanceMetrixDict.h Commands/ExitCommand.h Commands/CommandData.h
OUTS	= server.out
OUTC	= client.out
CC	= g++
FLAGS	= -g -c -std=c++11
LFLAGS	= -pthread

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

CLI.o: Commands/CLI.cpp
	$(CC) $(FLAGS) Commands/CLI.cpp

SocketIO.o: IOs/SocketIO.cpp
	$(CC) $(FLAGS) IOs/SocketIO.cpp

StandartIO.o: IOs/StandartIO.cpp
	$(CC) $(FLAGS) IOs/StandartIO.cpp

CommandData.o: Commands/CommandData.cpp
	$(CC) $(FLAGS) Commands/CommandData.cpp

UploadUnclassCommand.o: Commands/UploadUnclassCommand.cpp
	$(CC) $(FLAGS) Commands/UploadUnclassCommand.cpp

AlgoSettingCommand.o: Commands/AlgoSettingCommand.cpp
	$(CC) $(FLAGS) Commands/AlgoSettingCommand.cpp

ClassifyCommand.o: Commands/ClassifyCommand.cpp
	$(CC) $(FLAGS) Commands/ClassifyCommand.cpp

DisplayResultsCommand.o: Commands/DisplayResultsCommand.cpp
	$(CC) $(FLAGS) Commands/DisplayResultsCommand.cpp

DownloadResultsCommand.o: Commands/DownloadResultsCommand.cpp
	$(CC) $(FLAGS) Commands/DownloadResultsCommand.cpp

DistanceMetrixDict.o: Commands/DistanceMetrixDict.cpp
	$(CC) $(FLAGS) Commands/DistanceMetrixDict.cpp

ExitCommand.o: Commands/ExitCommand.cpp
	$(CC) $(FLAGS) Commands/ExitCommand.cpp

clean:
	rm -f $(OBJS) $(OUTC) $(OUTS) $(OBJSCLIENT)
