#include <vector>
#include <string>
#include <sstream>
#include "VectorCheck.h"
#include "RecieveCheckServer.h"
#include <iostream>

using namespace std;
/**
* constractor - splits the information in the string to k, distance type and vector
* @param recieve type string.
*/
RecieveCheckServer::RecieveCheckServer(string line){
    stringstream recieve(line);
    string subStringRecieve;
    vector<string> recieveList;
    while(getline(recieve, subStringRecieve, ' '))
    {
        recieveList.push_back(subStringRecieve);
    }
    if(recieveList.size() < 3) {
        k = 0;
        distance = "";
    }
    try
    {
        string recieveK = recieveList.back();
        recieveList.pop_back();
        k = stoi(recieveK);
        distance = recieveList.back();
        recieveList.pop_back();
        int sizeVector = recieveList.size();
        for (int i = 0; i < sizeVector; i++)
        {
            vect.push_back(stod(recieveList[i]));
        }
    }
    catch(const exception& e)
    {
        k = 0;
        distance = "";
    }
}
/**
* get k, if k = 0 the string invalid.
* @return - k - the last word of the string
*/
int RecieveCheckServer::getRecieveK(){
    return k;
}
/**
* get distance type, if return null the string invalid.
* @return - distance type.
*/
string RecieveCheckServer::getDistanceOption(){
    return distance;
}
/**
* get vector.
* @return - vector type double.
*/
vector<double> RecieveCheckServer::getVector(){
    return vect;
}
