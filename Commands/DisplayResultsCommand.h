#ifndef DISPLAYRESULTSCOMMAND_H_
#define DISPLAYRESULTSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class DisplayResultsCommand : public Command {
private:
    vector<Database> result;
    bool dataAlreadyUpload;
    bool dataSorted;
    string getResultInFormat();
public:
	
    DisplayResultsCommand(DefaultIO* io);
	void execute();
    void setTestVector(vector<Database> newResult);
    string getDescription();
};

#endif