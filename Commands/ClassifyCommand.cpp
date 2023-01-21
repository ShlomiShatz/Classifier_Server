#include <string>
#include <vector>
#include <map>
#include "ClassifyCommand.h"
#include "Command.h"
#include "../Server/SelectSort.h"
#include "DistanceMetrixDict.h"
using namespace std;



ClassifyCommand::ClassifyCommand(DefaultIO* io) : Command("classify data",io) {
}
void ClassifyCommand::calcDistance(vector<double> vect){
    map<string, Distance> typeDistance = DistanceMetrixDict::getInstance();
    for (Database& elem : classify) {
        elem.setDistRes(typeDistance[distanceMetrix].getDistance(elem.getSpecs(), vect));
    }
}
string ClassifyCommand::getType(){
    double pivot = SelectSort::getK(classify, k);
    SelectSort::partitionFinal(classify, pivot);
    map<string, int> counterMap;
    int i, max = 0;
    string maxClass = " ";
    //Iterates through the vector and calculates the number of appearances
    for (i = 0; i < k; i++) {
        //Checks the classification of this specific member
        string curClass = classify[i].getClassify();
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
    if (classify.size() == 0){
        m_dio->write("please upload data");
        return;
    }
    //if need to do it
    if (classify.size() < k){
        m_dio->write("please update your k");
        return;
    }
    for (Database& elem : test) {
        calcDistance(elem.getSpecs());
        elem.setClassify(getType());
    }
    m_dio->write("classifying data complete");
}

void ClassifyCommand::setK(int newK){
    k = newK;
}
void ClassifyCommand::setDistanceMetrix(string newDistanceMetrix){
    distanceMetrix = newDistanceMetrix;
}
void ClassifyCommand::setClassifyVector(vector<Database> newClassify){
    classify = newClassify;
}
void ClassifyCommand::setTestVector(vector<Database> newTest){
    test = newTest;
}
int ClassifyCommand::getK(){
    return k;
}
string ClassifyCommand::getDistanceMetrix(){
    return distanceMetrix;
}
vector<Database> ClassifyCommand::getClassifyVector(){
    return classify;
}
vector<Database> ClassifyCommand::ClassifyCommand::getTestVector(){
    return test;
}
    
