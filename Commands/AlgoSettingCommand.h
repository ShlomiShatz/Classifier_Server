#ifndef ALGOSETTINGCOMMAND_H_
#define ALGOSETTINGCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class AlgoSettingCommand : public Command {

private:

    string getInfo();
    void updateValue(string input);
    
public:

    AlgoSettingCommand(DefaultIO* io, CommandData* cd);	
	void execute();
    string getDescription();
};

#endif