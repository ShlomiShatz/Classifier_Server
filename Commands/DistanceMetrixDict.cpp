#include <map>
#include "../Distances/CanberraDistance.h"
#include "../Distances/ChebyshevDistance.h"
#include "../Distances/Distance.h"
#include "../Distances/EuclideanDistance.h"
#include "../Distances/MinkowskiDistance.h"
#include "../Distances/TaxicabGeometry.h"
#include "DistanceMetrixDict.h"

map<string, Distance> DistanceMetrixDict::getInstance(){
    if (typeDistance.empty()){
        DistanceMetrixDict();
    }
    return typeDistance;
}


DistanceMetrixDict::DistanceMetrixDict(){
    typeDistance["AUC"] = EuclideanDistance();
    typeDistance["MAN"] = TaxicabGeometry();
    typeDistance["CHB"] = ChebyshevDistance();
    typeDistance["CAN"] = CanberraDistance();
    typeDistance["MIN"] = MinkowskiDistance();
}