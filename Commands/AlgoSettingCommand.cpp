#include <string>
#include <map>
#include "AlgoSettingCommand.h"
#include "Command.h"
#include "../Distances/Distance.h"
#include "DistanceMetrixDict.h"

using namespace std;

AlgoSettingCommand::AlgoSettingCommand(DefaultIO* io) {
    Command::m_description = "algorithm settings";
    Command::m_dio = io;
    k = 5;
    distanceMetric = "AUC";
    MaxK = -1;
}
string AlgoSettingCommand::getInfo(){
    string info = "The current KNN parameters are: K = ";
    info = info + to_string(k);
    info = info + ", distance metric = ";
    info = info + distanceMetric;
    return info;
}
void AlgoSettingCommand::setMaxK(int MaxiK) {
    MaxK = MaxiK;
}
void AlgoSettingCommand::updateValue(string input){
    int potentialK = 0;
    string newMetric;
    string msg = "";
    if (input == "") {
        return;
    }
    int found = input.find(" ");
    if (found == string::npos){
        throw 0;
    }
    string subString = input.substr(0,found);
    input = input.substr(found + 1);
    map<string, Distance*> typeDistance = DistanceMetrixDict::getInstance();
    if (typeDistance.count(input) <= 0){
        msg = msg + "invalid value for metric";
    }
    try{
        potentialK = stoi(subString);
    }catch(exception e){
        if (msg == ""){
            msg = "invalid value for K";
        }else{
            msg = msg + "\ninvalid value for K";
        }
        m_dio->write(msg);
        return;
    }
    string potentialStringK = to_string(potentialK);
    if (potentialStringK != subString){
        if (msg == ""){
            msg = "invalid value for K";
        }else{
            msg = msg + "\ninvalid value for K";
        }
        m_dio->write(msg);
        return;
    }
    if (potentialK > MaxK || potentialK < 1){
        if (msg == ""){
            msg = "invalid value for K";
        }else{
            msg = msg + "\ninvalid value for K";
        }
        m_dio->write(msg);
        return;
    }
    if (msg != "")
    {
        m_dio->write(msg);
    }
    
    k = potentialK;
    distanceMetric = input;
    m_dio->write("ok");
}

void AlgoSettingCommand::execute() {
    m_dio->write(getInfo());
    string data = m_dio->read();
    updateValue(data);
}

string AlgoSettingCommand::getDescription() {
    return m_description;
}
int AlgoSettingCommand::getK(){
    return k;
}

string AlgoSettingCommand::getDistanceMetric(){
    return distanceMetric;
} 
