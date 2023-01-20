#include <string>
#include "ExitCommand.h"

using namespace std;



ExitCommand::ExitCommand() {
    Command::m_description = "exit";
}

void ExitCommand::execute() {}
    
