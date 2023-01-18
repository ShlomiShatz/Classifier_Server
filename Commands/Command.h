#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "DefaultIO.h"

using namespace std;

class Command {

private:

    string description;
    DefaultIO dio;

public:
	
	virtual void execute() = 0;
    
};

#endif