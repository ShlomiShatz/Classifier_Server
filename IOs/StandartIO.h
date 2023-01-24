#ifndef STANDARTIO_H_
#define STANDARTIO_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

/**
 * The class incharge of communicating with the user through the commandline
*/
class StandartIO: public DefaultIO {

    public:

        /**
         * Default destructor
        */
        ~StandartIO();

        /**
         * Default constructor
        */
        StandartIO();

        /**
         * The function incharge of taking input from commandline
         * @return the input taken
        */
        string read() override;

        /**
         * The function incharge of printing data to the commandline
         * @param s the data printed
        */
        void write(string s) override;

};

#endif