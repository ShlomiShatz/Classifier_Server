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
    // vector<Database> result;
    // bool dataAlreadyUpload;
    // bool dataSorted;
    string getResultInFormat();
public:
    DownloadResultsCommand(DefaultIO* io, CommandData* cd);
	void execute();
    // void setTestVector(vector<Database> newResult);
    string getDescription();
    // void setDataAlreadyUpload(bool change);
    // void setDataSorted(bool change);
};

#endif