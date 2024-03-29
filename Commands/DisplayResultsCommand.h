#ifndef DISPLAYRESULTSCOMMAND_H_
#define DISPLAYRESULTSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

/**
 * The class that incharge of the algorythm settings*************8
*/
class DisplayResultsCommand : public Command {

private:

    /**
    * The function returns the results of the classification in a specific format
    * @return the formatted results
    */
    string getResultInFormat();

public:
	
    /**
    * Default constructor
    */
    DisplayResultsCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    DisplayResultsCommand(DefaultIO* io, CommandData* cd);

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