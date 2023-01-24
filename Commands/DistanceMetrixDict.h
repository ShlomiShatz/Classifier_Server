#ifndef DISTANCEMETRIXDICT_H_
#define DISTANCEMETRIXDICT_H_
#include <map>
#include <string>
#include "../Distances/Distance.h"

using namespace std;

/**
 * The class that holds the map for classifing metrics and distances
*/
class DistanceMetrixDict{

private:

    //The map containing the information
    static map<string, Distance*> m_typeDistance;

    /**
    * The constructor of the class
    */
    DistanceMetrixDict();

public:

    /**
     * Returns the map
     * @return the distances map
    */
    static map<string, Distance*> getInstance();
};

#endif