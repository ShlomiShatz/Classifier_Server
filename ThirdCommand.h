#ifndef THIRDCOMMAND_H_
#define THIRDCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class ThirdCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    ThirdCommand();
	void execute();
    
};

#endif