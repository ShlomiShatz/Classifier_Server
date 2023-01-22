#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <fstream>
#include "ClientVectorCheck.h"
#include "../IOs/SocketIO.h"
#include "../IOs/StandartIO.h"
#include "../OpenFile.h"

using namespace std;

/**
    * The main function of the client
    * @param argc number of commandline parameters
    * @param argv the commandline parameters
    */
int main(int argc, char** argv) {

    //Checks for enough arguments before trying to access it
    if (argc != 3) {
        cout << "wrong number of arguments" << endl;
        return 0;
    }

    //Setting up the connection with the server
    int sock = 0;
    try {
        const char* ip_address = argv[1];
        if(!ClientVectorCheck::checkIP(argv[1])){
            throw exception();
        }
        //Checking the validity of the port number
        const int port_no = ClientVectorCheck::kCheck(argv[2]);
        if (port_no > 65355 || port_no < 1024) throw exception(); 
        //Connecting to the server
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(ip_address);
        sin.sin_port = htons(port_no);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        //If the socket did not set up right, prints an error and closes the program
        if (sock < 0) { 
            perror("error creating socket"); 
            return 0;
        }
        //If the connection failed, prints an error and closes the program
        if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { 
            perror("error connecting to server"); 
            return 0;
        }
    // If any check turned out bad, prints an error and close the program
    } catch (exception &err) {
        cout << "invalid port or ip" << endl;
        return 0;
    }
    SocketIO sockio(sock);
    StandartIO standio;
    //The loop that runs the client
    string fullMsg = sockio.read();
    while (true) {
        //Takes the full message from the server
        // cout << "-456" << endl;//****************************************************
        // cout << "-470" << endl;//****************************************************
        int finish = fullMsg.find("~~~");
        if (finish != string::npos) {
            fullMsg = fullMsg.erase(finish, string::npos);
            standio.write(fullMsg);
            // cout << "-489" << endl;//****************************************************
            string input = standio.read();
            // cout << "-495" << endl;//****************************************************
            try {
                sockio.write(input);
            } catch (exception &err) {
                cout << "failed to send message" << endl;
            }
        } else if (fullMsg.find("|||") != string::npos) {
            finish = fullMsg.find("|||");
            fullMsg = fullMsg.erase(finish, string::npos);
            standio.write(fullMsg);
            // cout << "-477" << endl;//****************************************************
            string input = standio.read();
            // cout << "-488" << endl;//****************************************************
            try {
                sockio.write(input);
            } catch (exception &err) {
                cout << "failed to send message" << endl;
                continue;
            }
            if(input == "5") {
                fullMsg = sockio.read();
                if (fullMsg.find("please upload data") == string::npos && fullMsg.find("please classify the data") == string::npos) {
                    string path = standio.read();
                    ofstream file(path);
                    file << fullMsg;
                    sockio.write("");
                } else {
                    continue;
                }
            } else if(input == "8") {
                sockio.write(input);
                break;
            }
        } else {
            standio.write(fullMsg);
            if(fullMsg.find("Please upload your local train CSV file.") != string::npos || fullMsg.find("Please upload your local test CSV file.") != string::npos) {
                string input = standio.read();
                string fileToSend;
                try {
                    OpenFile classifyFile(input);
                    fileToSend = classifyFile.ClientFile();
                } catch (int exc) {
                    standio.write("invalid input");
                    sockio.write("-1");
                    fullMsg = sockio.read();
                    continue;
                }
                try {
                    sockio.write(fileToSend);
                } catch (exception &err) {
                    standio.write("failed to send file");
                }
            }
        }
        fullMsg = sockio.read();
    }
    return 0;
}
