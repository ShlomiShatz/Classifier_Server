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
    EuclideanDistance euc;
    m_typeDistance["AUC"] = &euc;
    TaxicabGeometry tax;
    m_typeDistance["MAN"] = &tax;
    ChebyshevDistance cheby;
    m_typeDistance["CHB"] = &cheby;
    CanberraDistance cancan;
    m_typeDistance["CAN"] = &cancan;
    MinkowskiDistance minko;
    m_typeDistance["MIN"] = &minko;
    
}