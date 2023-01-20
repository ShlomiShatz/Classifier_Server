#ifndef CLI_H_
#define CLI_H_

#include "Command.h"
#include <vector>

using namespace std;

class CLI {
private:

	vector<Command> m_coms;
	DefaultIO *m_dio;

public:
	
	CLI(DefaultIO* dio);
	void start();
	string printMenu();
    
};

#endif