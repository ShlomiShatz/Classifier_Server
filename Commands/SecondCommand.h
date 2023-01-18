#ifndef SECONDCOMMAND_H_
#define SECONDCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class SecondCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:

    SecondCommand();	
	void execute();
    
};

#endif