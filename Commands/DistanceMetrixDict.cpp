#include <map>
#include "../Distances/CanberraDistance.h"
#include "../Distances/ChebyshevDistance.h"
#include "../Distances/Distance.h"
#include "../Distances/EuclideanDistance.h"
#include "../Distances/MinkowskiDistance.h"
#include "../Distances/TaxicabGeometry.h"
#include "DistanceMetrixDict.h"

map<string, Distance*> DistanceMetrixDict::m_typeDistance;

map<string, Distance*> DistanceMetrixDict::getInstance(){
    if (m_typeDistance.empty()){
        DistanceMetrixDict();
    }
    return m_typeDistance;
}


DistanceMetrixDict::DistanceMetrixDict(){
    m_typeDistance["AUC"] = new EuclideanDistance();
    m_typeDistance["MAN"] = new TaxicabGeometry();
    m_typeDistance["CHB"] = new ChebyshevDistance();
    m_typeDistance["CAN"] = new CanberraDistance();
    m_typeDistance["MIN"] = new MinkowskiDistance();
    
}