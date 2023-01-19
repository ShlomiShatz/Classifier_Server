#ifndef UPLOADUNCLASSCOMMAND_H_
#define UPLOADUNCLASSCOMMAND_H_

#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

class UploadUnclassCommand : public Command {

private:

    string description;
    DefaultIO *dio;
    
public:
	
    UploadUnclassCommand();

	void execute();
    
};

#endif