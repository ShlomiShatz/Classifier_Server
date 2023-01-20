#ifndef ALGOSETTINGCOMMAND_H_
#define ALGOSETTINGCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class AlgoSettingCommand : public Command {

private:

    int k;
    string distanceMetric;
    
public:
    AlgoSettingCommand();	
	void execute();
};

#endif