#ifndef DOWNLOADRESULTSCOMMAND_H_
#define DOWNLOADRESULTSCOMMAND_H_

#include <string>
#include <vector>
#include "../Server/Database.h"
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class DownloadResultsCommand : public Command {
private:
    vector<Database> result;
    bool dataAlreadyUpload;
    bool dataSorted;
    string getResultInFormat();
public:
    DownloadResultsCommand(DefaultIO* io);
	void execute();
    void setTestVector(vector<Database> newResult);
    
};

#endif