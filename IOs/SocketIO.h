#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

class SocketIO : public DefaultIO {
    private:

        int sock;

        //string convertToChar(char[] buffer);

    public:

        SocketIO(int sock);

        string read();

        string readAll(int length);

        void write(string input);

};

#endif

