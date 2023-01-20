#include <string>
#include <sstream>
#include "UploadUnclassCommand.h"
#include "../Server/VectorCheck.h"

using namespace std;

UploadUnclassCommand::UploadUnclassCommand() {
    Command::m_description = "upload an unclassified csv data file";
}

//check if the end char is \n
vector<Database> UploadUnclassCommand::createDatabase(string input){
    vector<string> row;
    vector<Database> vect;
    string line, word, temp;
    bool didPassFirst = false;
    int rowSize = 0;
    int found = input.find("\n");
    if (found == string::npos){
        throw 0;
    }
    string subString = input.substr(0,found);
    input = input.substr(found + 1);
    //need to change the funcion to comma
    row = VectorCheck::stringToVectorString(subString);
    int size = row.size();
    Database db(row);
    vect.push_back(db);
    if (subString.length() != 0){
        row.push_back(subString);
    } else {
        throw 0;
    }
    while (found != string::npos) {
        row.clear();
        string subString = input.substr(0,found);
        row = VectorCheck::stringToVectorString(subString);
        if (size != row.size()){
            throw 0;
        }
        input = input.substr(found + 1);
        Database db(row);
        vect.push_back(db);
    }
    return vect;
}
void UploadUnclassCommand::execute() {
    Command::m_dio->write("Please upload your local train CSV file.");
    string data = Command::m_dio->read();
    try{
        vectorClassify = UploadUnclassCommand::createDatabase(data);
    } catch(int e){
        Command::m_dio->write("invalid input");
        return;
    }
    Command::m_dio->write("Upload complete.");
    Command::m_dio->write("Please upload your local test CSV file.");
    data = Command::m_dio->read();
    try{
        vectorUnClassify = UploadUnclassCommand::createDatabase(data);
    }catch(int e){
        Command::m_dio->write("invalid input");
        vectorClassify.clear();
        return;
    }
    Command::m_dio->write("Upload complete.");
}

    
