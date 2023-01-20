#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"

using namespace std;

class Command {

protected:

    string m_description;
    DefaultIO *m_dio;

public:
	
	virtual void execute();

    string getDescription() { return m_description; }
    
    ~Command() {}
    
};

#endif