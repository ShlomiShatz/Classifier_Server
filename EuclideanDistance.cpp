#include <iostream>
#include <vector>
#include <cmath>
#include "Distance.h"
#include "EuclideanDistance.h"

using namespace std;

/**
* Default constructor
*/
EuclideanDistance::EuclideanDistance():Distance::Distance() {}

/**
* The function calculates the distance between two vectors using Euclidean formula
* @param vector1 the first vector
* @param vector2 the second vector
* @return the distance
*/
double EuclideanDistance::getDistance(vector<double> vect1, vector<double> vect2){
    double distance = calculateSumOfSubVector(vect1, vect2, 2);
    distance = pow(distance,  0.5);
    return distance;
}