#include <string>
#include "ExitCommand.h"

using namespace std;



ExitCommand::ExitCommand(DefaultIO* io) {
    Command::m_description = "exit";
    Command::m_dio = io;
}

void ExitCommand::execute() {
    //need to check if work
    m_dio->~DefaultIO();
    return;
}

string ExitCommand::getDescription() {
    return m_description;
}
    
