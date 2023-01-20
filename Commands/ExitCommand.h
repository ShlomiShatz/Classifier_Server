#ifndef EXITCOMMAND_H_
#define EXITCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class ExitCommand : public Command {

private:

    string description;
    DefaultIO *dio;
    
public:
	
    ExitCommand();
	void execute();
    
};

#endif