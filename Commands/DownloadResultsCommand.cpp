#include <string>
#include "DownloadResultsCommand.h"
#include "CommandData.h"
#include "Command.h"

using namespace std;

/**
* Default constructor
*/
DownloadResultsCommand::DownloadResultsCommand() {}

/**
* The constructor of the class
* @param io the DefaultIO pointer for this command
* @param cd the full data structure of this program
*/
DownloadResultsCommand::DownloadResultsCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "download results";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

/**
* The function that runs this command
*/
void DownloadResultsCommand::execute() {
    //Checks if the data was uploaded and classified
    if (!Command::m_currentData->getDataUpload()) {
        Command::m_dio->write("please upload data");
        return;
    }
    else if (!Command::m_currentData->getDataSort()) {
        Command::m_dio->write("please classify the data");
        return;
    }
    //If so, sends the results
    Command::m_dio->write(getResultInFormat());
    Command::m_dio->read();
}

/**
* The function returns the results of the classification in a specific format
* @return the formatted results
*/
string DownloadResultsCommand::getResultInFormat(){
    int size = Command::m_currentData->getUnClassifyVect().size();
    string format = "";
    for (int i = 1; i <= size; i++){
        format = format + to_string(i);
        format = format + "\t";
        format = format + Command::m_currentData->getUnClassifyVect()[i-1].getClassify();
        format = format + "\n";
    }
    return format;
}

/**
* The function returns the description of this command
* @return the description
*/
string DownloadResultsCommand::getDescription() {
    return m_description;
}   
