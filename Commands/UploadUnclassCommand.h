#ifndef UPLOADUNCLASSCOMMAND_H_
#define UPLOADUNCLASSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class UploadUnclassCommand : public Command {

private:

    string description;
    DefaultIO dio;
    vector<Database> vectorClassify;
    vector<Database> vectorUnClassify;
    
public:
	
    UploadUnclassCommand();
    vector<Database> createDatabase(string input);
	void execute();
    
};

#endif