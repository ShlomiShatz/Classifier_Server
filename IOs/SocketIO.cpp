#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "SocketIO.h"

#include <iostream>//******************************************************************************

using namespace std;


SocketIO::SocketIO(int sock) : sock(sock) {}


// string SocketIO::read() {
//     string fullMsg = "";
//     string fixedMsg = "";
//     int finish = 0;
//     bool printMsg = true;
//     do {
//         bool finishFlag = false;
//         do {
//             //Receives the data from the server
//             char buffer[4096] = {0};
//             int expected_data_len = sizeof(buffer);
//             int read_bytes = recv(sock, buffer, expected_data_len, 0);
//             if (read_bytes == 0) {
//                 continue;
//             }
//             else if (read_bytes < 0) {
//                 break;
//             }
//             string partMsg(buffer);
//             if (printMsg) {
//                 cout << "---" << partMsg << "---" << endl;//*******************************************************
//                 printMsg = false;
//             }
//             fullMsg.append(partMsg);
//             if (partMsg.length() < 4096) {
//                 break; 
//             }
//             finishFlag = true;
//             finish = fullMsg.find("\r\t\r\t");
//         } while(finish == string::npos);
//         if(finishFlag) {
//             while (finish != string::npos) {
//                 fullMsg = fullMsg.erase(finish, 4);
//                 finish = fullMsg.find("\r\t\r\t");
//             }
//         }
//         finish = fullMsg.find("\r\n\r\n");
//     } while(finish == string::npos);
//     if (finish == string::npos) {
//         return "error reading message";
//     }
//     while(finish != string::npos) {
//         fixedMsg = fullMsg.erase(finish, 4);
//         finish = fixedMsg.find("\r\n\r\n");
//     }
//     return fixedMsg;
// }

// void SocketIO::write(string input) {
//     int input_size = input.length();
//     while (input_size > 4092) {
//         string current = input.substr(0, 4092);
//         current.append("\r\t\r\t");
//         //Checks for the input and converts to char*
//         int data_len = current.length();
//         char *data_addr = &current[0];
//         //Send the message to the server
//         sleep(0.01);//**********************************************************
//         int sent_bytes = send(sock, data_addr, data_len, 0);
//         //Check if the message was sent
//         if (sent_bytes < 0) {
//             cout << "error sending message" << endl;
//             return;
//         }
//         input = input.substr(4092);
//         input_size -= 4092;
//     }
//     input.append("\r\n\r\n");
//     //Checks for the input and converts to char*
//     int data_len = input.length();
//     char *data_addr = &input[0];
//     //Send the message to the server
//     sleep(0.01);//**********************************************************
//     int sent_bytes = send(sock, data_addr, data_len, 0);
//     //Check if the message was sent

//     if (sent_bytes < 0) {
//         cout << "error sending message" << endl;
//     }
    
// }
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
    //cout << "###" << message << "###" << endl;
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

    //cout << "REST: " << rest << endl;
    if (rest == 0) return fullMsg;
    char buffer[rest + 1] = {0};
    // string Buffstr(buffer);
    //cout << "BUFFSTR: " << "***" << Buffstr << "***" << endl;
    int expected_data_len = sizeof(buffer);
    //cout << "size buffer: " << expected_data_len << endl;
    int read_bytes = recv(sock, buffer, expected_data_len - 1, 0);
    if (read_bytes < 0) {
        perror("system operation failed");
        return "";
    }
    string partMsg(buffer);
    //cout << "BUFFSTR- after: " << "***" << Buffstr << "***" << endl;
    //cout << "$$$" << partMsg << "$$$" << endl;
    fullMsg.append(partMsg);
    return fullMsg;
}

void SocketIO::write(string input) {
    int input_size = input.length();
    string current = to_string(input_size);
    //cout << "NUMBER: " << current << endl;
    current.append("^");
    current.append(input);
    //cout << "---" << current << "---" << endl;
    //Checks for the input and converts to char*
    int data_len = current.length();
    cout << "DATA LEN: " << data_len << endl;//*************************************************************
    char *data_addr = &current[0];
    //Send the message to the server
    int sent_bytes = send(sock, data_addr, data_len, 0);
    //Check if the message was sent
    if (sent_bytes < 0) {
        cout << "error sending message" << endl;
        return;
    }
}
