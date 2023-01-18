#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

class SocketIO : public DefaultIO {

    public:

        string read(int sock);

        void write(string input, int sock);

};

#endif
