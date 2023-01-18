#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

class SocketIO : public DefaultIO {
    private:

        int sock;

    public:

        SocketIO(int sock) : sock(sock) {}

        string read();

        void write(string input);

};

#endif

