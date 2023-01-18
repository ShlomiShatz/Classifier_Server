#ifndef CLASSIFYCOMMAND_H_
#define CLASSIFYCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class ClassifyCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    ClassifyCommand();
	void execute();
    
};

#endif