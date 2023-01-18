#ifndef DOWNLOADRESULTSCOMMAND_H_
#define DOWNLOADRESULTSCOMMAND_H_

#include <string>
#include "DefaultIO.h"
#include "Command.h"

using namespace std;

class DownloadResultsCommand : public Command {

private:

    string description;
    DefaultIO dio;
    
public:
	
    DownloadResultsCommand();
	void execute();
    
};

#endif