#ifndef CLASSIFYCOMMAND_H_
#define CLASSIFYCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class ClassifyCommand : public Command {
    
public:
	
    ClassifyCommand();
	void execute();
    
};

#endif