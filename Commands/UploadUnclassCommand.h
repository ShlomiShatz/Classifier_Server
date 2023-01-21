#ifndef UPLOADUNCLASSCOMMAND_H_
#define UPLOADUNCLASSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class UploadUnclassCommand : public Command {

private:

    vector<Database> vectorClassify;
    vector<Database> vectorUnClassify;

    
public:
	
    UploadUnclassCommand(DefaultIO* io);
    vector<Database> createDatabase(string input);
	void execute();
    
};

#endif