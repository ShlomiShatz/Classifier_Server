#include <string>

class SocketIO : public DefaultIO {

    public:

        string read(int sock);

        void write(string input, int sock);

}