#ifndef CLASSIFYCOMMAND_H_
#define CLASSIFYCOMMAND_H_

#include <string>
#include <vector>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"


using namespace std;

class ClassifyCommand : public Command {
private:
    int k;
    string distanceMetrix;
    vector<Database> classify;
    vector<Database> test;
    void calcDistance(vector<double> vect);
    string getType();
public:
	
    ClassifyCommand(DefaultIO* io);
	void execute();
    void setK(int newK);
    void setDistanceMetrix(string newDistanceMetrix);
    void setClassifyVector(vector<Database> newClassify);
    void setTestVector(vector<Database> newTest);
    int getK();
    string getDistanceMetrix();
    vector<Database> getClassifyVector();
    vector<Database> getTestVector();
};

#endif