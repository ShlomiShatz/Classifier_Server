#ifndef MINKOWSKIDISTANCE_H_
#define MINKOWSKIDISTANCE_H_
#include <vector>
#include "Distance.h"

using namespace std;

/**
 * A class incharge of calculating the Minkowski distance, inherets from the Distance class
*/
class MinkowskiDistance : public Distance {
public:
    /**
    * Constructor
    */
    MinkowskiDistance();

    /**
    * The function calculates the distance between two vectors using Minkowski formula
    * @param vector1 the first vector
    * @param vector2 the second vector
    * @return the distance
    */
    double getDistance(vector<double> vector1, vector<double> vector2);
};
#endif