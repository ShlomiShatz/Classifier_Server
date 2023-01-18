#ifndef CLI_H_
#define CLI_H_

#include "Command.h"

using namespace std;

class CLI {

private:

	vector<Command> coms;
	DefaultIO dio;

public:
	
	CLI();
	static void start();
    
};

#endif