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
	
    string getDescription();
    UploadUnclassCommand(DefaultIO* io);
    vector<Database> createDatabase(string input);
	void execute();
    int getMaxK();
    vector<Database> getClassifyVect();
    vector<Database> getUnClassifyVect();
};

#endif