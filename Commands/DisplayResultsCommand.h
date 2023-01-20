#ifndef DISPLAYRESULTSCOMMAND_H_
#define DISPLAYRESULTSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class DisplayResultsCommand : public Command {

public:
	
    DisplayResultsCommand();
	void execute();
    
};

#endif