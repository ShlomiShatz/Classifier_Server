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

/**
* Default constructor
*/
AlgoSettingCommand::AlgoSettingCommand() {}

/**
* The constructor of the class
* @param io the DefaultIO pointer for this command
* @param cd the full data structure of this program
*/
AlgoSettingCommand::AlgoSettingCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "algorithm settings";
    Command::m_dio = io;
    Command::m_currentData = cd;
}

/**
* The function returns the information of the current algorythm settings
* @return the current settings
*/
string AlgoSettingCommand::getInfo(){
    //Builds the string and returns it
    string info = "The current KNN parameters are: K = ";
    info = info + to_string(Command::m_currentData->getCurrentK());
    info = info + ", distance metric = ";
    info = info + Command::m_currentData->getMatric();
    info = info + "~~~";
    return info;
}

/**
* The function updates the algorythm settings
* @param input settings to be updated by
*/
void AlgoSettingCommand::updateValue(string input) {
    //Creates variables to be used later
    int potentialK = 0;
    string newMetric;
    string msg = "";
    //Checks if the input is empty
    if (input.empty()) {
        return;
    }
    //Splits the input based on spaces
    int counter = 0;
    stringstream SStr(input);
    string temp, kString = "", dist = "";
    while(getline(SStr, temp, ' ')) {
        //If this is the first input initializes it as the K
        if (counter == 0) {
            kString = temp;
        //If this is the second input initializes it as the metric
        } else if (counter == 1) {
            dist = temp;
        }
        counter++;
    }
    //If there were too many or less arguments than needed, sends error message
    if (counter != 2) {
            Command::m_dio->write("invalid input");
            return;
    }
    //Check the metric entered based on the distances map
    if (DistanceMetrixDict::getInstance().count(dist) <= 0){
        msg = "invalid value for metric";
    }
    try {
        //Checks the K value for validity
        potentialK = RecieveCheckServer::numCheck(kString);
    } catch(exception e) {
        if (msg.empty()) {
            msg = "invalid value for K";
            Command::m_dio->write(msg);
        } else {
            msg.append("\ninvalid value for K");
            Command::m_dio->write(msg);
        }
        return;
    }
    //Checks if the K value is too big
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
    //Sends the error message
    if (!msg.empty()) {
        Command::m_dio->write(msg);
        return;
    }
    //If all was right, sets the settings
    Command::m_currentData->setCurrentK(potentialK);
    Command::m_currentData->setMatric(dist);
}

/**
* The function that runs this command
*/
void AlgoSettingCommand::execute() {
    Command::m_dio->write(getInfo());
    string data = Command::m_dio->read();
    updateValue(data);
}

string AlgoSettingCommand::getDescription() {
    return m_description;
}
