#include <string>
#include "ExitCommand.h"

using namespace std;



ExitCommand::ExitCommand(DefaultIO* io): Command("exit",io) {
}

void ExitCommand::execute() {
    //need to check if work
    m_dio->~DefaultIO();
    return;
}
    
