#ifndef DOWNLOADRESULTSCOMMAND_H_
#define DOWNLOADRESULTSCOMMAND_H_

#include <string>
#include <vector>
#include "../Server/Database.h"
#include "../IOs/DefaultIO.h"
#include "CommandData.h"
#include "Command.h"

using namespace std;

class DownloadResultsCommand : public Command {
private:

    string getResultInFormat();

public:

    /**
    * Default constructor
    */
    DownloadResultsCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    DownloadResultsCommand(DefaultIO* io, CommandData* cd);
	void execute();

    /**
    * The function returns the description of this command
    * @return the description
    */
    string getDescription();
    
};

#endif