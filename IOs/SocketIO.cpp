#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "SocketIO.h"

using namespace std;

string SocketIO::read() {
    string fullMsg = "";
    int finish = 0;
    do {
            //Receives the data from the server
            char buffer[4096] = {0};
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(this.sock, buffer, expected_data_len, 0);
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
        return fullMsg;
}

void SocketIO::write(string input) {
    input.append("\r\n\r\n");
    //Checks for the input and converts to char*
    int data_len = input.length();
    char *data_addr = &input[0];
    //Send the message to the server
    int sent_bytes = send(this.sock, data_addr, data_len, 0);
    //Check if the message was sent
    if (sent_bytes < 0) cout << "error sending message" << endl;
}