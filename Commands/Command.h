#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "CommandData.h"
#include "../IOs/DefaultIO.h"

using namespace std;

/**
 * The abstract class that represents commands
*/
class Command {

protected:

    //The description of this command
    string m_description;
    //The default IO object for this command
    DefaultIO* m_dio;
    //The data structure containing all of the information
    CommandData* m_currentData;

public:

    /**
    * The function that runs this command
    */
	virtual void execute() = 0;

    /**
    * The function returns the description of this command
    * @return the description
    */
    virtual string getDescription() = 0;
    
    
};

#endif