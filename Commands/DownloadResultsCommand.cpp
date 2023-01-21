#include <string>
#include "DownloadResultsCommand.h"
#include "Command.h"

using namespace std;



DownloadResultsCommand::DownloadResultsCommand(DefaultIO* io) {
    Command::m_description = "download results";
    Command::m_dio = io;
    dataAlreadyUpload = false;
    dataSorted = false;
}

void DownloadResultsCommand::execute() {
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
string DownloadResultsCommand::getResultInFormat(){
    int size = result.size();
    string format = "";
    for (int i = 1; i <= size; i++){
        format = format + to_string(i);
        format = format + ",";
        format = format + result[i-1].getClassify();
        format = format + "\n";
    }
    return format;
}
void DownloadResultsCommand::setTestVector(vector<Database> newResult){
    result = newResult;
}

string DownloadResultsCommand::getDescription() {
    return Command::m_description;
}
    
