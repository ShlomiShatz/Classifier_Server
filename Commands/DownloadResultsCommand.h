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
    DownloadResultsCommand();
    DownloadResultsCommand(DefaultIO* io, CommandData* cd);
	void execute();
    string getDescription();;
};

#endif