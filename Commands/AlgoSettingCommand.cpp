#include <string>
#include <map>
#include "AlgoSettingCommand.h"
#include "CommandData.h"
#include "Command.h"
#include "../Server/RecieveCheckServer.h"
#include "../Distances/Distance.h"
#include "DistanceMetrixDict.h"

using namespace std;

AlgoSettingCommand::AlgoSettingCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "algorithm settings";
    Command::m_dio = io;
    Command::m_currentData = cd;
}
string AlgoSettingCommand::getInfo(){
    string info = "The current KNN parameters are: K = ";
    info = info + to_string(Command::m_currentData->getCurrentK());
    info = info + ", distance metric = ";
    info = info + Command::m_currentData->getMatric();
    return info;
}
// void AlgoSettingCommand::setMaxK(int MaxiK) {
//     MaxK = MaxiK;
// }
void AlgoSettingCommand::updateValue(string input){
    int potentialK = 0;
    string newMetric;
    string msg = "";
    if (input.empty()) {
        return;
    }
    int found = input.find(" ");
    if (found == string::npos){
        throw 0;
    }
    string subString = input.substr(0, found);
    input = input.substr(found + 1);
    map<string, Distance*> typeDistance = DistanceMetrixDict::getInstance();
    if (typeDistance.count(input) <= 0){
        msg = "invalid value for metric";
    }
    try {
        potentialK = RecieveCheckServer::numCheck(subString);
    } catch(exception e) {
        if (msg.empty()){
            msg = "invalid value for K";
            Command::m_dio->write(msg);
        } else {
            msg.append("\ninvalid value for K");
            Command::m_dio->write(msg);
        }
        return;
    }
    // string potentialStringK = to_string(potentialK);
    // if (potentialStringK != subString){
    //     if (msg == ""){
    //         msg = "invalid value for K";
    //     }else{
    //         msg = msg + "\ninvalid value for K";
    //     }
    //     Command::m_dio->write(msg);
    //     return;
    // }
    if (potentialK > Command::m_currentData->getMaxK()) {
        if (msg.empty()) {
            msg = "invalid value for K";
            Command::m_dio->write(msg);
        } else {
            msg.append("\ninvalid value for K");
            Command::m_dio->write(msg);
        }
        return;
    }
    if (!msg.empty()) {
        Command::m_dio->write(msg);
        return;
    }
    Command::m_currentData->setCurrentK(potentialK);
    Command::m_currentData->setMatric(input);
    // Command::m_dio->write("ok");//********************************************************************************88
}

void AlgoSettingCommand::execute() {
    Command::m_dio->write(getInfo());
    string data = Command::m_dio->read();
    updateValue(data);
}

string AlgoSettingCommand::getDescription() {
    return m_description;
}
// int AlgoSettingCommand::getK(){
//     return k;
// }

// string AlgoSettingCommand::getDistanceMetric(){
//     return distanceMetric;
// } 
