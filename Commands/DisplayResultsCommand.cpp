#include <string>
#include "DisplayResultsCommand.h"
#include "CommandData.h"
#include "Command.h"

using namespace std;



DisplayResultsCommand::DisplayResultsCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "display results";
    Command::m_dio = io;
    Command::m_currentData = cd;
}
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
void DisplayResultsCommand::execute(){
    if (!Command::m_currentData->getDataUpload()){
        Command::m_dio->write("please upload data");
        return;
    }
    else if (!Command::m_currentData->getDataSort())
    {
        Command::m_dio->write("please classify the data");
        return;
    }
    Command::m_dio->write(getResultInFormat());
    Command::m_dio->read();
}

string DisplayResultsCommand::getDescription() {
    return m_description;
}
