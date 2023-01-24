#include <string>
#include "ExitCommand.h"
#include "CommandData.h"

using namespace std;

ExitCommand::ExitCommand() {}

ExitCommand::ExitCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "exit";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

void ExitCommand::execute() {
    //need to check if work
    // Command::m_dio->~DefaultIO();
    return;
}

string ExitCommand::getDescription() {
    return m_description;
}
    
