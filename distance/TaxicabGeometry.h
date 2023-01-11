#ifndef TAXICABGEOMETRY_H_
#define TAXICABGEOMETRY_H_
#include <vector>
#include "Distance.h"

using namespace std;

/**
 * A class incharge of calculating the Manhattan distance, inherets from the Distance class
*/
class TaxicabGeometry : public Distance {
public:
    /**
    * Constructor
    */
    TaxicabGeometry();

    /**
    * The function calculates the distance between two vectors using Manhattan formula
    * @param vector1 the first vector
    * @param vector2 the second vector
    * @return the distance
    */
    double getDistance(vector<double> vector1, vector<double> vector2);
};
#endif