#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

using namespace std;
/**
 * The class containing the classification of a given vector, its specification and the distance(if it was calculated)
*/
class Database {
private:

    //The specifications of the Database
    vector<double> m_specs;
    //The classification of the Database
    string m_clasify;
    //The distance
    double m_dist;

public:

    /**
     * The constructor of the class
     * @param line the line from csv file to be built by
    */
    Database(vector<string> line);

    /**
     * Overloads the '=' operator with this class
     * @param db - the parameter being applied by
     * @return the applied Database
    */
    Database& operator=(const Database& db);
    
    /**
     * Returns the calssification of the Database
     * @return the classification
    */
    string getClassify() const;

    /**
     * Returns the specifications of the Database
     * @return the specifications
    */
    vector<double> getSpecs() const;

    /**
     * Sets the calssification of the Database
     * @param str the classification being applied by
    */
    void setClassify(string str);

    /**
     * Sets the specifications of the Database
     * @param vect the vector of string being applied by
    */
    void setSpecs(vector<string> vect);

    /**
     * Sets the distance result of the Database
     * @param dist the result
    */
    void setDistRes(double dist);

    /**
     * Returns the distance result of the Database
     * @return the distance
    */
    double getDist() const;

};

#endif
