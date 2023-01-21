#ifndef DISTANCEMETRIXDICT_H_
#define DISTANCEMETRIXDICT_H_
#include <map>
#include <string>
#include "../Distances/Distance.h"

using namespace std;

class DistanceMetrixDict{
    private:
        static map<string, Distance> typeDistance;
        DistanceMetrixDict();
    public:
        static map<string, Distance> getInstance();
};

#endif