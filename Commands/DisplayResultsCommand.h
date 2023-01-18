#ifndef DISPLAYRESULTSCOMMAND_H_
#define DISPLAYRESULTSCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class DisplayResultsCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    DisplayResultsCommand();
	void execute();
    
};

#endif