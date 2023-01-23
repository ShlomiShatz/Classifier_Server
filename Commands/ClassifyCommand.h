#ifndef CLASSIFYCOMMAND_H_
#define CLASSIFYCOMMAND_H_

#include <string>
#include <vector>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"


using namespace std;

class ClassifyCommand : public Command {
private:
    void calcDistance(vector<double> vect);
    string getType();
public:
	
    ClassifyCommand();
    ClassifyCommand(DefaultIO* io, CommandData* cd);
	void execute();
    string getDescription();
};

#endif