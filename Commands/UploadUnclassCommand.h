#ifndef UPLOADUNCLASSCOMMAND_H_
#define UPLOADUNCLASSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

/**
 * The class that incharge of uploading the classification data
*/
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

    /**
     * The function creates the unclassified data vector
     * @param input the file being taken from the client as one string
     * @return the result vector of databases
    */
    vector<Database> createUnClassifiedDatabase(string input);

    /**
     * The function creates the classified data vector
     * @param input the file being taken from the client as one string
     * @return the result vector of databases
    */
    vector<Database> createClassifiedDatabase(string input);

    /**
    * The function that runs this command
    */
	void execute();

    /**
     * The function converts a string to a string vector
     * @param s the string being converted
     * @return the result vector
    */
    vector<string> toVectorString(string s);
    
    /**
     * Resets all the information in the data structure to default
    */
    void resetRecords();
    
};

#endif