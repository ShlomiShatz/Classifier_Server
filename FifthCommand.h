#ifndef FIFTHCOMMAND_H_
#define FIFTHCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class FifthCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    FifthCommand();
	void execute();
    
};

#endif