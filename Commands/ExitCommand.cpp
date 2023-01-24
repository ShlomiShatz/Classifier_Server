#include <string>
#include "ExitCommand.h"
#include "CommandData.h"

using namespace std;

/**
* Default constructor
*/
ExitCommand::ExitCommand() {}

/**
* The constructor of the class
* @param io the DefaultIO pointer for this command
* @param cd the full data structure of this program
*/
ExitCommand::ExitCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "exit";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

/**
* The function that runs this command
*/
void ExitCommand::execute() {
    return;
}

string ExitCommand::getDescription() {
    return m_description;
}
    
