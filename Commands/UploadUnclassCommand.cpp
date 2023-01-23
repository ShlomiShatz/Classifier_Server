#include <string>
#include <sstream>
#include "UploadUnclassCommand.h"
#include "CommandData.h"
#include "../Server/VectorCheck.h"
#include "Command.h"
#include "CLI.h"

#include <iostream>//*************************************************************************

using namespace std;

UploadUnclassCommand::UploadUnclassCommand() {}

UploadUnclassCommand::UploadUnclassCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "upload an unclassified csv data file";
    Command::m_dio = io;
    Command::m_currentData = cd;
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
    row = UploadUnclassCommand::toVectorString(temp);
    int size = row.size();
    Database db(row);
    vect.push_back(db);
    if (temp.length() != 0) {
        row.push_back(temp);
    } else {
        throw 0;
    }
    while (getline(SStr, temp, '\n')) {
        row.clear();
        row = UploadUnclassCommand::toVectorString(temp);
        if (size != row.size()){
            throw 0;
        }
        Database db(row);
        vect.push_back(db);
    }
    return vect;
}
void UploadUnclassCommand::execute() {
    Command::m_dio->write("Please upload your local train CSV file.");
    string data = Command::m_dio->read();
    if (data == "-1") {
        return;
    }
    try {
        cout << "READING" << endl;//************************************************************
        Command::m_currentData->setClassifyVect(UploadUnclassCommand::createDatabase(data));
        cout << "FINISHED" << endl;//************************************************************
        Command::m_currentData->setMaxK(Command::m_currentData->getClassifyVect().size());
    } catch(exception e) {
        Command::m_dio->write("invalid input");
        return;
    }
    Command::m_dio->write("Upload complete.");
    Command::m_dio->write("Please upload your local test CSV file.");
    data = Command::m_dio->read();
    try {
        Command::m_currentData->setUnClassifyVect(UploadUnclassCommand::createDatabase(data));
    } catch(exception e) {
        Command::m_dio->write("invalid input");
        Command::m_currentData->clearClassifyVect();
        Command::m_currentData->clearUnClassifyVect();
        Command::m_currentData->setDataUpload(false);
        Command::m_currentData->setDataSort(false);
        return;
    }
    Command::m_currentData->setDataUpload(true);
    Command::m_dio->write("Upload complete.");
}

string UploadUnclassCommand::getDescription() {
    return m_description;
}
