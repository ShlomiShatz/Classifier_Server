#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "SocketIO.h"

using namespace std;


SocketIO::SocketIO(int sock) : sock(sock) {}

string SocketIO::read() {
    string length = "";
    string receive = "";
    while (receive != "^"){
        length.append(receive);
        char buffer[2] = {0};
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len - 1, 0);
        if (read_bytes == 0) {
            return "";
        } else if (read_bytes < 0) {
            break;
        }
        string current(buffer);
        receive = current;
    }
    string message = readAll(stoi(length));
    return message;

}

string SocketIO::readAll(int length) {
    string fullMsg = "";
    int rest = length % 4000;
    int numPackets = length / 4000;
    int i;
    for (i = 0; i < numPackets; i++) {
        char buffer[4001] = {0};
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len - 1, MSG_WAITALL);
        if (read_bytes == 0) {
            continue;
        }
        else if (read_bytes < 0) {
            break;
        }
        string partMsg(buffer);
        fullMsg.append(partMsg);
    }

    if (rest == 0) return fullMsg;
    char buffer[rest + 1] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len - 1, 0);
    if (read_bytes < 0) {
        perror("system operation failed");
        return "";
    }
    string partMsg(buffer);
    fullMsg.append(partMsg);
    return fullMsg;
}

void SocketIO::write(string input) {
    int input_size = input.length();
    string current = to_string(input_size);
    current.append("^");
    current.append(input);
    //Checks for the input and converts to char*
    int data_len = current.length();
    char *data_addr = &current[0];
    //Send the message to the server
    int sent_bytes = send(sock, data_addr, data_len, 0);
    //Check if the message was sent
    if (sent_bytes < 0) {
        perror("error sending message");
        return;
    }
}
