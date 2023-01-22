#include <string>
#include "DownloadResultsCommand.h"
#include "CommandData.h"
#include "Command.h"

using namespace std;

DownloadResultsCommand::DownloadResultsCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "download results";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

void DownloadResultsCommand::execute() {
    if (!Command::m_currentData->getDataUpload()) {
        Command::m_dio->write("please upload data");
        return;
    }
    else if (!Command::m_currentData->getDataSort()) {
        Command::m_dio->write("please classify the data");
        return;
    }
    Command::m_dio->write(getResultInFormat());
    Command::m_dio->read();
}
string DownloadResultsCommand::getResultInFormat(){
    int size = Command::m_currentData->getUnClassifyVect().size();
    string format = "";
    for (int i = 1; i <= size; i++){
        format = format + to_string(i);
        format = format + ",";
        format = format + Command::m_currentData->getUnClassifyVect()[i-1].getClassify();
        format = format + "\n";
    }
    return format;
}

string DownloadResultsCommand::getDescription() {
    return m_description;
}   
