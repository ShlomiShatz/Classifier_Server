#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

/**
 * The IO class incharge of socket communication
*/
class SocketIO : public DefaultIO {
    
    private:

        //The socket being connected
        int sock;

    public:

        /**
         * The constructor of the class
         * @param sock the socket being connected to
        */
        SocketIO(int sock);

        /**
         * The function that receives data
         * @return the data received
        */
        string read();

        /**
         * The function reads the rest of the data based on its length
         * @param length the length of the received data
         * @return the full message
        */
        string readAll(int length);

        /**
         * The function incharge of sending data
         * @param input the string being sent
        */  
        void write(string input);

};

#endif

