#ifndef ALGOSETTINGCOMMAND_H_
#define ALGOSETTINGCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class AlgoSettingCommand : public Command {

private:
    
    /**
    * The function returns the information of the current algorythm settings
    * @return the current settings
    */
    string getInfo();

    /**
    * The function updates the algorythm settings
    * @param input settings to be updated by
    */
    void updateValue(string input);
    
public:

    /**
    * Default constructor
    */
    AlgoSettingCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    AlgoSettingCommand(DefaultIO* io, CommandData* cd);	

    /**
    * The function that runs this command
    */
	void execute();

    /**
    * The function returns the description of this command
    * @return the description
    */
    string getDescription();
    
};

#endif