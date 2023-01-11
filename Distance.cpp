#include <vector>
#include <cmath>
#include "Distance.h"

using namespace std;


/**
* Default constructor
*/
Distance::Distance(){}

/**
 * The function calculates the sum of all the sub vector values according to their order
 * @param vector1 the first vector
 * @param vector2 the second vector
 * @param powNeeded the needed power number
 * @return the resulted sum
*/
double Distance::calculateSumOfSubVector(vector<double> vector1, vector<double> vector2, int powNeeded) {
    double distance = 0;
    for (int i = vector1.size() - 1 ; i >= 0 ;i--) {
        double sum = pow(abs(vector1[i] - vector2[i]), powNeeded);
        distance = distance + sum;
    }
    return distance;
}