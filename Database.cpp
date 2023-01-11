#include <string>
#include <vector>
#include "Database.h"
#include "VectorCheck.h"

/**
 * Returns the classification of the Database
 * @return the classification
*/
string Database::getClassify() const { return m_clasify; }

/**
 * Returns the specifications of the Database
 * @return the specifications
*/
vector<double> Database::getSpecs() const { return m_specs; }

/**
 * Overloads the '=' operator with this class
 * @param db - the parameter being applied by
 * @return the applied Database
*/
Database& Database::operator=(const Database& db){
    //Clears the current specifications
    m_specs.clear();
    //Equals the distance
    m_dist = db.getDist();
    //Sets the classification
    setClassify(db.getClassify());
    //Adds the specifications to the applied vector
    for (auto& elem2 : db.getSpecs()) {
        m_specs.push_back(elem2);
    }
    return *this;
}

/**
 * Sets the calssification of the Database
 * @param str the classification being applied by
*/
void Database::setClassify(string str) { m_clasify = str; }

/**
 * Sets the specifications of the Database
 * @param vect the vector of string being applied by
*/
void Database::setSpecs(vector<string> vect) {
    //Checks the validity of the vector and applies it
    m_specs = VectorCheck::stringVectToVector(vect);
}

/**
 * Sets the distance result of the Database
 * @param dist the result
*/
void Database::setDistRes(double dist) {
    m_dist = dist;
}

/**
 * Returns the distance result of the Database
 * @return the distance
*/
double Database::getDist() const {
    return m_dist;
}

/**
 * The constructor of the class
 * @param line the line from csv file to be built by
*/
Database::Database(vector<string> line) {
    //Sets the classification by the end of the vector
    setClassify(line.back());
    //Pops it
    line.pop_back();
    //Sets the rest of the vector as specifications
    setSpecs(line);
    //Default distance is 0
    m_dist = 0;
}
