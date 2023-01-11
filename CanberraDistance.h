#ifndef CANBERRADISTANCE_H_
#define CANBERRADISTANCE_H_
#include <vector>
#include "Distance.h"

using namespace std;

/**
 * A class incharge of calculating the Canberra distance, inherets from the Distance class
*/
class CanberraDistance : public Distance {
public:
    /**
    * Constructor
    */
    CanberraDistance();

    /**
    * The function calculates the distance between two vectors using Canberra formula
    * @param vector1 the first vector
    * @param vector2 the second vector
    * @return the distance
    */
    virtual double getDistance(vector<double> vector1, vector<double> vector2);
};
#endif