#ifndef UPLOADUNCLASSCOMMAND_H_
#define UPLOADUNCLASSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

class UploadUnclassCommand : public Command {
    
public:
	
    /**
    * Default constructor
    */
    UploadUnclassCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    UploadUnclassCommand(DefaultIO* io, CommandData* cd);

    /**
    * The function returns the description of this command
    * @return the description
    */
    string getDescription();

    vector<Database> createDatabase(string input);

    /**
    * The function that runs this command
    */
	void execute();

    vector<string> toVectorString(string s);
    
    void resetRecords();
    
};

#endif