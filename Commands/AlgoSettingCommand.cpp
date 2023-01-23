#include <string>
#include <map>
#include <sstream>
#include "AlgoSettingCommand.h"
#include "CommandData.h"
#include "Command.h"
#include "../Server/RecieveCheckServer.h"
#include "../Distances/Distance.h"
#include "../Distances/CanberraDistance.h"
#include "../Distances/ChebyshevDistance.h"
#include "../Distances/Distance.h"
#include "../Distances/EuclideanDistance.h"
#include "../Distances/MinkowskiDistance.h"
#include "../Distances/TaxicabGeometry.h"
#include "DistanceMetrixDict.h"

using namespace std;

AlgoSettingCommand::AlgoSettingCommand() {}

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
    info = info + "~~~";
    return info;
}

void AlgoSettingCommand::updateValue(string input){
    int potentialK = 0;
    string newMetric;
    string msg = "";
    if (input.empty()) {
        return;
    }
    int counter = 0;
    stringstream SStr(input);
    string temp, kString = "", dist = "";
    while(getline(SStr, temp, ' ')) {
        if (counter == 0) {
            kString = temp;
        } else if (counter == 1) {
            dist = temp;
        }
        counter++;
    }
    if (counter != 2) {
        //ask what to print/do **********************************************
            Command::m_dio->write("invalid input");
            return;
    }
    map<string, Distance*> typeDistance = DistanceMetrixDict::getInstance();
    if (typeDistance.count(dist) <= 0){
        msg = "invalid value for metric";
    }
    try {
        potentialK = RecieveCheckServer::numCheck(kString);
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
    Command::m_currentData->setMatric(dist);
}

void AlgoSettingCommand::execute() {
    Command::m_dio->write(getInfo());
    string data = Command::m_dio->read();
    updateValue(data);
}

string AlgoSettingCommand::getDescription() {
    return m_description;
}
