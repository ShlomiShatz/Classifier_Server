#ifndef UPLOADUNCLASSCOMMAND_H_
#define UPLOADUNCLASSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class UploadUnclassCommand : public Command {
    
public:
	
    UploadUnclassCommand();
    UploadUnclassCommand(DefaultIO* io, CommandData* cd);
    string getDescription();
    vector<Database> createDatabase(string input);
	void execute();
    vector<string> toVectorString(string s);
    
};

#endif