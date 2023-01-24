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
	
    /**
    * Default constructor
    */
    ClassifyCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    ClassifyCommand(DefaultIO* io, CommandData* cd);

    /**
    * The function that runs this command
    */
	void execute();
    string getDescription();
};

#endif