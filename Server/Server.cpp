#include <iostream>
#include <string>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "RecieveCheckServer.h"
#include "../OpenFile.h"
#include "../IOs/SocketIO.h"
#include "../Commands/CLI.h"


using namespace std;

/**
 * open socket ,recieve clients and give them answer
 * @param argc num of argv that recieved from the command line
 * @param argv - words that recieved from the command line
 * @return 0 when the function end
*/
int main(int argc, char** argv) {
    if (argc != 2) {
	    cout << "wrong number of arguments" << endl; 
        return 0;
    }
    int sock = 0;
    try {
        //Checking the validity of the port number
        const int port_no = RecieveCheckServer::numCheck(argv[1]);
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
    } catch(exception &err) {
        cout << "invalid port" << endl;
        return 0;
    }
    if (listen(sock, 5) < 0) {
        perror("system operation failed");
        return 0;
    }
    while(true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("system operation failed");
            continue;
        }
        SocketIO sockio(client_sock);
        // CLI cli(&sockio);
        // cli.start();
    }
}
