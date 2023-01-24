#ifndef COMMANDDATA_H_
#define COMMANDDATA_H_

#include <string>
#include <vector>
#include "../Server/Database.h"

using namespace std;

class CommandData {
private:

    int m_currentK;
    int m_maxK;
    string m_matric;
    bool m_dataAlreadyUpload;
    bool m_dataSorted;
    vector<Database> m_classifyVect;
    vector<Database> m_unClassifyVect;

public:

    CommandData();
    void setCurrentK(int k);
    void setMaxK(int k);
    void setMatric(string s);
    void setDataUpload(bool b);
    void setDataSort(bool b);
    int getCurrentK();
    int getMaxK();
    string getMatric();
    bool getDataUpload();
    bool getDataSort();
    void setClassifyVect(vector<Database> vect);
    void setUnClassifyVect(vector<Database> vect);
    vector<Database>& getClassifyVect();
    vector<Database>& getUnClassifyVect();
    void clearClassifyVect();
    void clearUnClassifyVect();
    
};

#endif