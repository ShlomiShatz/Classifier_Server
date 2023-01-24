#include <map>
#include "../Distances/CanberraDistance.h"
#include "../Distances/ChebyshevDistance.h"
#include "../Distances/Distance.h"
#include "../Distances/EuclideanDistance.h"
#include "../Distances/MinkowskiDistance.h"
#include "../Distances/TaxicabGeometry.h"
#include "DistanceMetrixDict.h"

map<string, Distance*> DistanceMetrixDict::m_typeDistance;

/**
 * Returns the map
 * @return the distances map
*/
map<string, Distance*> DistanceMetrixDict::getInstance() {
    //Checks if the map already exists, if not - constructs it
    if (m_typeDistance.empty()){
        DistanceMetrixDict();
    }
    return m_typeDistance;
}

/**
* The constructor of the class
*/
DistanceMetrixDict::DistanceMetrixDict() {
    m_typeDistance["AUC"] = new EuclideanDistance();
    m_typeDistance["MAN"] = new TaxicabGeometry();
    m_typeDistance["CHB"] = new ChebyshevDistance();
    m_typeDistance["CAN"] = new CanberraDistance();
    m_typeDistance["MIN"] = new MinkowskiDistance();
}