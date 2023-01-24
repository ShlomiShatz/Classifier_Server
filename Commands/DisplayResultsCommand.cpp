#include <string>
#include "DisplayResultsCommand.h"
#include "CommandData.h"
#include "Command.h"

using namespace std;

/**
* Default constructor
*/
DisplayResultsCommand::DisplayResultsCommand() {}

/**
* The constructor of the class
* @param io the DefaultIO pointer for this command
* @param cd the full data structure of this program
*/
DisplayResultsCommand::DisplayResultsCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "display results";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

/**
* The function returns the results of the classification in a specific format
* @return the formatted results
*/
string DisplayResultsCommand::getResultInFormat(){
    int size = Command::m_currentData->getUnClassifyVect().size();
    string format = "";
    for (int i = 1; i <= size; i++){
        format = format + to_string(i);
        format = format + "\t";
        format = format + Command::m_currentData->getUnClassifyVect()[i-1].getClassify();
        format = format + "\n";
    }
    format = format + "Done.~~~";
    return format;
}

/**
* The function that runs this command
*/
void DisplayResultsCommand::execute(){
    //Checks if data was uploaded and classified
    if (!Command::m_currentData->getDataUpload()){
        Command::m_dio->write("please upload data");
        return;
    }
    else if (!Command::m_currentData->getDataSort())
    {
        Command::m_dio->write("please classify the data");
        return;
    }
    //If so, sends the format
    Command::m_dio->write(getResultInFormat());
    Command::m_dio->read();
}

/**
* The function returns the description of this command
* @return the description
*/
string DisplayResultsCommand::getDescription() {
    return m_description;
}
