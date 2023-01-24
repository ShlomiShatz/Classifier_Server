#include <string>
#include <sstream>
#include "UploadUnclassCommand.h"
#include "CommandData.h"
#include "../Server/VectorCheck.h"
#include "Command.h"
#include "CLI.h"

using namespace std;

/**
* Default constructor
*/
UploadUnclassCommand::UploadUnclassCommand() {}

/**
* The constructor of the class
* @param io the DefaultIO pointer for this command
* @param cd the full data structure of this program
*/
UploadUnclassCommand::UploadUnclassCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "upload an unclassified csv data file";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

void UploadUnclassCommand::resetRecords() {
        Command::m_currentData->clearClassifyVect();
        Command::m_currentData->clearUnClassifyVect();
        Command::m_currentData->setDataUpload(false);
        Command::m_currentData->setDataSort(false);
        Command::m_currentData->setMaxK(-1);
        Command::m_currentData->setCurrentK(5);
        Command::m_currentData->setMatric("AUC");
        Command::m_dio->write("invalid input");
}

vector<string> UploadUnclassCommand::toVectorString(string s) {
    vector<string> vect;
    string temp;
    stringstream SStr(s);
    while (getline(SStr, temp, ',')) {
        vect.push_back(temp);
    }
    return vect;
}

//check if the end char is \n
vector<Database> UploadUnclassCommand::createDatabase(string input){
    vector<string> row;
    vector<Database> vect;
    string line, word, temp;
    bool didPassFirst = false;
    int rowSize = 0;
    stringstream SStr(input);
    getline(SStr, temp, '\n');
    if (temp.length() == 0) throw exception();
    row = UploadUnclassCommand::toVectorString(temp);
    int size = row.size();
    Database db(row);
    vect.push_back(db);
    if (temp.length() != 0) {
        row.push_back(temp);
    } else {
        throw exception();
    }
    while (getline(SStr, temp, '\n')) {
        row.clear();
        row = UploadUnclassCommand::toVectorString(temp);
        if (size != row.size()){
            throw exception();
        }
        Database db(row);
        vect.push_back(db);
    }
    return vect;
}

/**
* The function that runs this command
*/
void UploadUnclassCommand::execute() {
    Command::m_dio->write("Please upload your local train CSV file.");
    string data = Command::m_dio->read();
    if (data == "-1") {
        UploadUnclassCommand::resetRecords();
        return;
    }
    try {
        Command::m_currentData->setClassifyVect(UploadUnclassCommand::createDatabase(data));
        Command::m_currentData->setMaxK(Command::m_currentData->getClassifyVect().size());
    } catch(exception e) {
        UploadUnclassCommand::resetRecords();
        return;
    }
    Command::m_dio->write("Upload complete.");
    Command::m_dio->write("Please upload your local test CSV file.");
    data = Command::m_dio->read();
    if (data == "-1") {
        UploadUnclassCommand::resetRecords();
        return;
    }
    try {
        Command::m_currentData->setUnClassifyVect(UploadUnclassCommand::createDatabase(data));
    } catch(exception e) {
        UploadUnclassCommand::resetRecords();
        return;
    }
    if (Command::m_currentData->getUnClassifyVect()[0].getSpecs().size() != Command::m_currentData->getClassifyVect()[0].getSpecs().size()) {
        UploadUnclassCommand::resetRecords();
        return;
    }
    Command::m_currentData->setDataUpload(true);
    Command::m_dio->write("Upload complete.");
}

/**
* The function returns the description of this command
* @return the description
*/
string UploadUnclassCommand::getDescription() {
    return m_description;
}
