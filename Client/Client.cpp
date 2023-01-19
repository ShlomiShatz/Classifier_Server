#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "ClientVectorCheck.h"
#include "../IOs/SocketIO.h"

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
    SocketIO sio = new SocketIO(sock);
    //The loop that runs the client
    while (true) {
        //Takes the full message from the server
        string fullMsg = "";
        int finish = 0;
        //Loop that takes all the input from the server
        do {
            //Receives the data from the server
            char buffer[4096] = {0};
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                continue;
            }
            else if (read_bytes < 0) {
                cout << "error reading message" << endl;
                continue;
            }
            string partMsg(buffer);
            fullMsg.append(partMsg);
            finish = fullMsg.find("\r\n\r\n");
        } while(finish == string::npos);
        //Fixes the message and prints it
        fullMsg = fullMsg.substr(0, finish);
        cout << fullMsg << endl;
        if(fullMsg == "Please upload your local CSV file." || fullMsg == "Please upload your local test CSV file.") {
            string input;
            //Getting the input from the user
            getline(cin, input);
            char *data_addr;
            try {
                OpenFile classifyFile(input);
                data_addr = classifyFile.ClientFile();
            } catch (int exc) {
                //If an exception was thrown, sends an error and closes the program
                cout << "invalid input" << endl;
                continue;
            }
            //Checks for the input and converts to char*
            int data_len = strlen(data_len);
            //Send the message to the server
            int sent_bytes = send(sock, data_addr, data_len, 0);
            //Check if the message was sent
            if (sent_bytes < 0) {
                cout << "error sending message" << endl;
                continue;
            }
            continue;//Insert SocketIO, handle exceptions
        }
        string input;
        //Getting the input from the user
        getline(cin, input);
        if(input == "5") {
           //Input path and receive file********************************************** 
        }
        input.append("\r\n\r\n");
        //Checks for the input and converts to char*
        int data_len = input.length();
        char *data_addr = &input[0];
        //Send the message to the server
        int sent_bytes = send(sock, data_addr, data_len, 0);
        //Check if the message was sent
        if (sent_bytes < 0) {
            cout << "error sending message" << endl;
            continue;
        }
    }
    //When the loop brakes, closes the socket and closing the program
    close(sock);
    return 0;
}
