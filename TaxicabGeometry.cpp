#include <iostream>
#include <vector>
#include <cmath>
#include "Distance.h"
#include "TaxicabGeometry.h"

using namespace std;

/**
* Default constructor
*/
TaxicabGeometry::TaxicabGeometry():Distance::Distance() {}

/**
* The function calculates the distance between two vectors using Manhattan formula
* @param vector1 the first vector
* @param vector2 the second vector
* @return the distance
*/
double TaxicabGeometry::getDistance(vector<double> vector1, vector<double> vector2){
    double distance = calculateSumOfSubVector(vector1, vector2 ,1);
    return distance;
}