#include <string>
#include <vector>
#include <map>
#include "ClassifyCommand.h"
#include "CommandData.h"
#include "Command.h"
#include "../Server/SelectSort.h"
#include "../Distances/CanberraDistance.h"
#include "../Distances/ChebyshevDistance.h"
#include "../Distances/Distance.h"
#include "../Distances/EuclideanDistance.h"
#include "../Distances/MinkowskiDistance.h"
#include "../Distances/TaxicabGeometry.h"
#include "DistanceMetrixDict.h"

using namespace std;

ClassifyCommand::ClassifyCommand() {}

ClassifyCommand::ClassifyCommand(DefaultIO* io, CommandData* cd) {
    Command::m_description = "classify data";
    Command::m_dio = io;
    Command::m_currentData = cd;
}
void ClassifyCommand::calcDistance(vector<double> vect){
    map<string, Distance*> typeDistance = DistanceMetrixDict::getInstance();
    for (Database& elem : Command::m_currentData->getClassifyVect()) {
        elem.setDistRes(typeDistance[Command::m_currentData->getMatric()]->getDistance(elem.getSpecs(), vect));
    }
}
string ClassifyCommand::getType(){
    double pivot = SelectSort::getK(Command::m_currentData->getClassifyVect(), Command::m_currentData->getCurrentK());
    SelectSort::partitionFinal(Command::m_currentData->getClassifyVect(), pivot);
    map<string, int> counterMap;
    int i, max = 0;
    string maxClass = " ";
    //Iterates through the vector and calculates the number of appearances
    for (i = 0; i < Command::m_currentData->getCurrentK(); i++) {
        //Checks the classification of this specific member
        string curClass = Command::m_currentData->getClassifyVect()[i].getClassify();
        //If it exists in the map already, increment it
        if (counterMap.count(curClass)) counterMap[curClass]++;
        //If not, create it and apply 1
        else counterMap[curClass] = 1;
        //If the incremented/applied key has higher appearances than the current maximum, replace it
        if (max < counterMap[curClass]) {
            max = counterMap[curClass];
            maxClass = curClass;
        }
    }
    //Returns the maximum
    return maxClass;
}
void ClassifyCommand::execute() {
    if (Command::m_currentData->getClassifyVect().size() == 0){
        m_dio->write("please upload data");
        return;
    }
    //if need to do it
    if (Command::m_currentData->getClassifyVect().size() < Command::m_currentData->getCurrentK()){
        m_dio->write("please update your k");
        return;
    }
    for (Database& elem : Command::m_currentData->getUnClassifyVect()) {

        calcDistance(elem.getSpecs());
        elem.setClassify(getType());
    }
    Command::m_currentData->setDataSort(true);
    Command::m_dio->write("classifying data complete");
}

string ClassifyCommand::getDescription() {
    return m_description;
}
