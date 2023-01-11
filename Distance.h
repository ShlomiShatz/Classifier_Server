#ifndef DISTANCE_H_
#define DISTANCE_H_
#include <vector>

using namespace std;

/**
 * The distance class, implementing one method and holds the distance itself virtual, for the inheretors to apply
*/
class Distance {
public:
    /**
    * Constructor
    */
    Distance();

    /**
    * The a virtual base function to calculate the distance between two vectors
    * @param vector1 the first vector
    * @param vector2 the second vector
    * @return the distance
    */
    virtual double getDistance(vector<double> vector1, vector<double> vector2) = 0;

    /**
     * The function calculates the sum of all the sub vector values according to their order
     * @param vector1 the first vector
     * @param vector2 the second vector
     * @param powNeeded the needed power number
     * @return the resulted sum
    */
    double calculateSumOfSubVector(vector<double> vector1, vector<double> vector2, int powNeeded);
};
#endif