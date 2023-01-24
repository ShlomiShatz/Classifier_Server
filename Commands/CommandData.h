#ifndef COMMANDDATA_H_
#define COMMANDDATA_H_

#include <string>
#include <vector>
#include "../Server/Database.h"

using namespace std;

/**
 * The data structure that contains all the information of this client
*/
class CommandData {
private:

    //The current K
    int m_currentK;
    //The maximum K
    int m_maxK;
    //The metric
    string m_matric;
    //The data flags
    bool m_dataAlreadyUpload;
    bool m_dataSorted;
    //The data vectors
    vector<Database> m_classifyVect;
    vector<Database> m_unClassifyVect;

public:

    /**
     * The constructor for this class
    */
    CommandData();

    /**
     * Sets the current K
     * @param k the k being set
    */
    void setCurrentK(int k);

    /**
     * Sets the max K
     * @param k the k being set
    */
    void setMaxK(int k);

    /**
     * Sets the metric
     * @param s the metric being set
    */
    void setMatric(string s);

    /**
     * Sets the data upload flag
     * @param b the boolean value being set
    */
    void setDataUpload(bool b);

    /**
     * Sets the data sort flag
     * @param b the boolean value being set
    */
    void setDataSort(bool b);

    /**
     * Returns the current K
     * @return the current k
    */
    int getCurrentK();

    /**
     * Returns the max K
     * @return the max k
    */
    int getMaxK();

    /**
     * Returns the current metric
     * @return the current metric
    */
    string getMatric();

    /**
     * Returns the data upload flag
     * @return the upload flag
    */
    bool getDataUpload();

    /**
     * Returns the data sort flag
     * @return the sort flag
    */
    bool getDataSort();

    /**
     * Sets the current classify vector
     * @param vect the vector being set
    */
    void setClassifyVect(vector<Database> vect);

    /**
     * Sets the current unclassified vector
     * @param vect the vector being set
    */
    void setUnClassifyVect(vector<Database> vect);

    /**
     * Returns the classify vector
     * @return the classify vector
    */
    vector<Database>& getClassifyVect();

    /**
     * Returns the unclassified vector
     * @return the unclassified vector
    */
    vector<Database>& getUnClassifyVect();

    /**
     * Clears the current classify vector
    */
    void clearClassifyVect();

    /**
     * Clears the current unclassified vector
    */
    void clearUnClassifyVect();
    
};

#endif