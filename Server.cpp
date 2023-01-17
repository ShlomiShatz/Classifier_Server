#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include "distance/Distance.h"
#include "SelectSort.h"
#include "VectorCheck.h"
#include "Database.h"
#include "distance/EuclideanDistance.h"
#include "distance/TaxicabGeometry.h"
#include "distance/MinkowskiDistance.h"
#include "distance/CanberraDistance.h"
#include "distance/ChebyshevDistance.h"
#include "RecieveCheckServer.h"
#include "OpenFile.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


using namespace std;

/**
 * Returns the class of a given vector based on its k neares neighbors
 * @param vect the vector being checked
 * @param k the number of neighbors to be checked
 * @return the classification result
*/
string retClass(vector<Database> vect, int k) {
    //Defines a map to count the results by specifications and number of appearances
    map<string, int> counterMap;
    int i, max = 0;
    string maxClass = " ";
    //Iterates through the vector and calculates the number of appearances
    for (i = 0; i < k; i++) {
        //Checks the classification of this specific member
        string curClass = vect[i].getClassify();
        //If it exists in the map already, increment it
        if (counterMap.count(curClass)) counterMap[curClass]++;
        //If not, create it and apply 1
        else counterMap[curClass] = 1;
        //If the incremented/applied key has higher appearances than the current maximum, replace it
        if (max < counterMap[curClass]) {
            max = counterMap[curClass];
            maxClass = curClass;
        }
    }
    //Returns the maximum
    return maxClass;
}

/**
 * send to the client invalid message
 * @param client_sock socket for the client
*/
void invalidSend(int client_sock) {
    char invalidMessage[] = "invalid input\r\n\r\n";
    int size = sizeof(invalidMessage);
    int sent_bytes = send(client_sock, invalidMessage, size, 0);
    if (sent_bytes < 0) {
		perror("operation system failed");
    }
}

/**
 * send to the client the type of the vector according to serverRecv
 * @param client_sock socket for the client
 * @param db - the vectors that got from csv file
 * @param typeDistance - distance object map
 * @param serverRecv - Information about the received message
*/
void sendType(int client_sock, vector<Database> db, map<string, Distance*> typeDistance, RecieveCheckServer serverRecv) {
    int k = serverRecv.getRecieveK();
    string distType = serverRecv.getDistanceOption();
    vector<double> vect = serverRecv.getVector();
    if ((k > db.size() || k < 1) || (typeDistance.count(distType) <= 0) || (vect.size() != db[0].getSpecs().size())) {
        invalidSend(client_sock);
        return;
    }
    //Calculates the distance of each vector and inserts it properly, based on the user's choice
    for (auto& elem : db) {
        elem.setDistRes(typeDistance[distType]->getDistance(elem.getSpecs(), vect));
    }
    //Using Select algorithm, calculates the pivot number based on the k nearest neighbors
    double pivot = SelectSort::getK(db, k);
    //Partitions the vector based on the pivot
    SelectSort::partitionFinal(db, pivot);
    string type = retClass(db, k) + "\r\n\r\n";
    char* classified = &type[0];
    //Send the classification calculated to the client
    int sent_bytes = send(client_sock, classified, type.size(), 0);
    if (sent_bytes < 0) {
        perror("operation system failed");
    }
}

/**
 * receive message from the client
 * @param client_sock socket for the client
 * @param db - the vectors that got from csv file
 * @param typeDistance - distance object map
 * @return if the connection need to continue
*/
bool recvFromClient(int client_sock, vector<Database> db, map<string, Distance*> typeDistance){
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    string data = "";
    string finish = "\r\n\r\n";
    do {
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        string newData{buffer};
        newData = newData.substr(0, read_bytes);
        data = data + newData;
        if (read_bytes == 0) {
            return false;
        }
        else if (read_bytes < 0) {
            perror("operation system failed");
            return true;
        }
    } while (data.find(finish) == string::npos);
    data = data.substr(0,data.size() - finish.size());
    
    string inputParam, inputVec, knum;
    int loc = 0;
     try {
        //Cuts all extra spaces from the string
        data = RecieveCheckServer::cutSpaces(data);
        //If the input is '-1' close the socket
        if (data == "-1") {
            return false;
        }
        //Checking the distance type
        loc = RecieveCheckServer::distCheck(data);
        //Splitting to parameters and vector
        inputParam = data.substr(loc, data.length() - 1);
        //Checks the parameter and using the K number
        knum = RecieveCheckServer::paramCheck(inputParam);
        //Checks the K number
        int k = RecieveCheckServer::numCheck(knum);
        inputVec = data.substr(0, loc - 1);
        //Checks the vector
        inputVec = RecieveCheckServer::stringCheckAndFix(inputVec);
        //Completes the string after all checks out
        data = inputVec.append(" " + inputParam);
    //If any turned bad, prints an error and continues the loop
    } catch (exception &err) {
        invalidSend(client_sock);
        return true;
    }
    RecieveCheckServer serverRecv(data);
    sendType(client_sock, db, typeDistance, serverRecv);
    return true;
}

/**
 * open socket ,recieve clients and give them answer
 * @param argc num of argv that recieved from the command line
 * @param argv - words that recieved from the command line
 * @return 0 when the function end
*/
int main(int argc, char** argv) {
    if (argc != 3) {
	cout << "invalid input" << endl; 
        return 0;
    }
    int sock = 0;
    try {
        //Checking the validity of the port number
        const int port_no = RecieveCheckServer::numCheck(argv[2]);
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port = htons(port_no);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("system operation failed");
            return 0;
        }
        if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("system operation failed");
            return 0;
        }
    }
    catch(exception &err)
    {
        cout << "invalid port" << endl;
        return 0;
    }
    //Creates the Database vector based on the third argument
    vector<Database> db;
    try {
        OpenFile classifyFile(argv[1]);
        db = classifyFile.CreateDatabase();
    } catch (int exc) {
        //If an exception was thrown, sends an error and closes the program
        cout << "Invalid file input!" << endl;
        return 0;
    }
    if (listen(sock, 5) < 0) {
        perror("system operation failed");
        return 0;
    }
    //Defines a map based on the string in the fourth argument and the different Distance derivative classes
    map<string, Distance*> typeDistance;
    typeDistance["AUC"] = new EuclideanDistance();
    typeDistance["MAN"] = new TaxicabGeometry();
    typeDistance["CHB"] = new ChebyshevDistance();
    typeDistance["CAN"] = new CanberraDistance();
    typeDistance["MIN"] = new MinkowskiDistance();
    while(true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("operation system failed");
            continue;
        }
        bool keepAlive = true;
        while(keepAlive){
            keepAlive = recvFromClient(client_sock, db, typeDistance);
        }
        close(client_sock);
    }
}
