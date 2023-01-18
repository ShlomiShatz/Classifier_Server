#ifndef FIRSTCOMMAND_H_
#define FIRSTCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class FirstCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    FirstCommand();

	void execute();
    
};

#endif