#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "CommandData.h"
#include "../IOs/DefaultIO.h"

using namespace std;

class Command {

protected:

    string m_description;
    DefaultIO* m_dio;
    CommandData* m_currentData;

public:

	virtual void execute() = 0;

    virtual string getDescription() = 0;
    
    
};

#endif