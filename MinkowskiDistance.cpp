#include <iostream>
#include <vector>
#include <cmath>
#include "Distance.h"
#include "MinkowskiDistance.h"

#define MINKOWSKICONST 2

using namespace std;

/**
* Default constructor
*/
MinkowskiDistance::MinkowskiDistance():Distance::Distance() {}

/**
* The function calculates the distance between two vectors using Minkowski formula
* @param vector1 the first vector
* @param vector2 the second vector
* @return the distance
*/
double MinkowskiDistance::getDistance(vector<double> vector1, vector<double> vector2){
    double distance = calculateSumOfSubVector(vector1, vector2, MINKOWSKICONST);
    distance = pow(distance,  1.0 / MINKOWSKICONST);
    return distance;
}