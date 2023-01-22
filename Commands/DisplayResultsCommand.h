#ifndef DISPLAYRESULTSCOMMAND_H_
#define DISPLAYRESULTSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class DisplayResultsCommand : public Command {
private:
    string getResultInFormat();
public:
	
    DisplayResultsCommand(DefaultIO* io, CommandData* cd);
	void execute();
    string getDescription();
};

#endif