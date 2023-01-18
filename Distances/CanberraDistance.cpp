#include <iostream>
#include <vector>
#include <cmath>
#include "Distance.h"
#include "CanberraDistance.h"

using namespace std;

/**
* Default constructor
*/
CanberraDistance::CanberraDistance():Distance::Distance() {}

/**
* The function calculates the distance between two vectors using Canberra formula
* @param vector1 the first vector
* @param vector2 the second vector
* @return the distance
*/
double CanberraDistance::getDistance(vector<double> vector1, vector<double> vector2){
    double distance = 0.0;
    for (int i = vector1.size() - 1 ; i >= 0 ;i--) {
        if (!(abs(vector1[i]) + abs(vector2[i]))) {
            continue;
        }
        double sum = abs(vector1[i] - vector2[i]) / (abs(vector1[i]) + abs(vector2[i]));
        distance = distance + sum;
    }
    return distance;
}