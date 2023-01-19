#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

class SocketIO : public DefaultIO {
    private:

        int sock;

    public:

        SocketIO();

        SocketIO(int sock);

        ~SocketIO();

        string read();

        void write(string input);

};

#endif

