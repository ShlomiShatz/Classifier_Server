#ifndef STANDARTIO_H_
#define STANDARTIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

class StandartIO: public DefaultIO {

    public:

        ~StandartIO();

        StandartIO();

        string read() override;

        void write(string s) override;

};

#endif