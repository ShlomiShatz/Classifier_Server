#ifndef EXITCOMMAND_H_
#define EXITCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class ExitCommand : public Command {

public:
	
    /**
    * Default constructor
    */
    ExitCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    ExitCommand(DefaultIO* io, CommandData* cd);

    /**
    * The function that runs this command
    */
	void execute();

    /**
    * The function returns the description of this command
    * @return the description
    */
    string getDescription();
    
};

#endif