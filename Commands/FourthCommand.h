#ifndef FOURTHCOMMAND_H_
#define FOURTHCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class FourthCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    FourthCommand();
	void execute();
    
};

#endif