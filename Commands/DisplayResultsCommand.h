#ifndef DISPLAYRESULTSCOMMAND_H_
#define DISPLAYRESULTSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class DisplayResultsCommand : public Command {
private:
    // vector<Database> result;
    // bool dataAlreadyUpload;
    // bool dataSorted;
    string getResultInFormat();
public:
	
    DisplayResultsCommand(DefaultIO* io, CommandData* cd);
	void execute();
    // void setTestVector(vector<Database> newResult);
    string getDescription();
    // void setDataAlreadyUpload(bool change);
    // void setDataSorted(bool change);
};

#endif