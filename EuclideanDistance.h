#ifndef EUCLIDEANDISTANCE_H_
#define EUCLIDEANDISTANCE_H_
#include <vector>
#include "Distance.h"

using namespace std;

/**
 * A class incharge of calculating the Euclidean distance, inherets from the Distance class
*/
class EuclideanDistance : public Distance {
public:
    /**
    * Constructor
    */
    EuclideanDistance();

    /**
    * The function calculates the distance between two vectors using Euclidean formula
    * @param vector1 the first vector
    * @param vector2 the second vector
    * @return the distance
    */
    double getDistance(vector<double> vect1, vector<double> vect2);
};
#endif