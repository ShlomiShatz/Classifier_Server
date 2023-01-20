#ifndef DOWNLOADRESULTSCOMMAND_H_
#define DOWNLOADRESULTSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class DownloadResultsCommand : public Command {
    
public:
	
    DownloadResultsCommand();
	void execute();
    
};

#endif