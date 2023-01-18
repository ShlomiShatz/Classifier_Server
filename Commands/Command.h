#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"

using namespace std;

class Command {

private:

    string description;
    DefaultIO dio;

public:
	
	virtual void execute();

    ~Command() {}
    
};

#endif