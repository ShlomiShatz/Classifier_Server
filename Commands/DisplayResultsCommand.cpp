#include <string>
#include "DisplayResultsCommand.h"
#include "Command.h"

using namespace std;



DisplayResultsCommand::DisplayResultsCommand(DefaultIO* io) {
    Command::m_description = "display results";
    Command::m_dio = io;
    dataAlreadyUpload = false;
    dataSorted = false;
}
string DisplayResultsCommand::getResultInFormat(){
    int size = result.size();
    string format = "";
    for (int i = 1; i <= size; i++){
        format = format + to_string(i);
        format = format + "\t";
        format = format + result[i-1].getClassify();
        format = format + "\n";
    }
    format = format + "Done.";
    return format;
}
void DisplayResultsCommand::execute(){
    if (!dataAlreadyUpload){
        m_dio->write("please upload data");
        return;
    }
    else if (!dataSorted)
    {
        m_dio->write("please classify the data");
        return;
    }
    m_dio->write(getResultInFormat());
    m_dio->read();
}
void DisplayResultsCommand::setTestVector(vector<Database> newResult){
    result = newResult;
}

string DisplayResultsCommand::getDescription() {
    return m_description;
}
