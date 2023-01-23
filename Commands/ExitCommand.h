#ifndef EXITCOMMAND_H_
#define EXITCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class ExitCommand : public Command {

public:
	
    ExitCommand();
    ExitCommand(DefaultIO* io, CommandData* cd);
	void execute();
    string getDescription();
};

#endif