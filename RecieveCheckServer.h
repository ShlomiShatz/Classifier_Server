#ifndef RECIEVECHECKSERVER_H_
#define RECIEVECHECKSERVER_H_

#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * The class splits the information in the string to k, distance type and vector
*/
class RecieveCheckServer {
private:
    string distance;
    int k;
    vector<double> vect;
public:
    /**
    * constractor - splits the information in the string to k, distance type and vector
    * @param recieve type string.
    */
    RecieveCheckServer(string recieve);
    /**
    * get k, if k = 0 the string invalid.
    * @return - k - the last word of the string
    */
    int getRecieveK();
    /**
    * get distance type, if return null the string invalid.
    * @return - distance type.
    */
    string getDistanceOption();
    /**
    * get vector.
    * @return - vector type double.
    */
    vector<double> getVector();
};

#endif
