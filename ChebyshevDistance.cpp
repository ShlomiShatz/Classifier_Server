#include <iostream>
#include <vector>
#include <cmath>
#include "Distance.h"
#include "ChebyshevDistance.h"

using namespace std;

/**
* Default constructor
*/
ChebyshevDistance::ChebyshevDistance():Distance::Distance() {}

/**
* The function calculates the distance between two vectors using Chebyshev formula
* @param vector1 the first vector
* @param vector2 the second vector
* @return the distance
*/
double ChebyshevDistance::getDistance(vector<double> vector1, vector<double> vector2){
    double distance = abs(vector1[0] - vector2[0]);
    for (int i = vector1.size()-1 ; i > 0 ;i--) {
        double checkSum = abs(vector1[i] - vector2[i]);
        if (distance < checkSum) {
            distance = checkSum;
        }
    }
    return distance;
}