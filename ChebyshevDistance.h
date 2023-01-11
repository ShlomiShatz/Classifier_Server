#ifndef CHEBYSHEVDISTANCE_H_
#define CHEBYSHEVDISTANCE_H_
#include <vector>
#include "Distance.h"

using namespace std;

/**
 * A class incharge of calculating the Chebyshev distance, inherets from the Distance class
*/
class ChebyshevDistance : public Distance {
public:
    /**
    * Constructor
    */
    ChebyshevDistance();

    /**
    * The function calculates the distance between two vectors using Chebyshev formula
    * @param vector1 the first vector
    * @param vector2 the second vector
    * @return the distance
    */
    virtual double getDistance(vector<double> vector1, vector<double> vector2);
};
#endif