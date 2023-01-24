#include <string>
#include "CommandData.h"

/**
 * The constructor for this class
*/
CommandData::CommandData() {
    //Sets all values as default
    m_currentK = 5;
    m_maxK = -1;
    m_matric = "AUC";
    m_dataAlreadyUpload = false;
    m_dataSorted = false;
    m_classifyVect.clear();
    m_unClassifyVect.clear();
}

/**
 * Sets the current K
 * @param k the k being set
*/
void CommandData::setCurrentK(int k) {
    m_currentK = k;
}

/**
 * Sets the max K
 * @param k the k being set
*/
void CommandData::setMaxK(int k) {
    m_maxK = k;
}

/**
 * Sets the metric
 * @param s the metric being set
*/
void CommandData::setMatric(string s) {
    m_matric = s;
}

/**
 * Sets the data upload flag
 * @param b the boolean value being set
*/
void CommandData::setDataUpload(bool b) {
    m_dataAlreadyUpload = b;
}

/**
 * Sets the data sort flag
 * @param b the boolean value being set
*/
void CommandData::setDataSort(bool b) {
    m_dataSorted = b;
}

/**
 * Returns the current K
 * @return the current k
*/
int CommandData::getCurrentK() {
    return m_currentK;
}

/**
 * Returns the max K
 * @return the max k
*/
int CommandData::getMaxK() {
    return m_maxK;
}

/**
 * Returns the current metric
 * @return the current metric
*/
string CommandData::getMatric() {
    return m_matric;
}

/**
 * Returns the data upload flag
 * @return the upload flag
*/
bool CommandData::getDataUpload() {
    return m_dataAlreadyUpload;
}

/**
 * Returns the data sort flag
 * @return the sort flag
*/
bool CommandData::getDataSort() {
    return m_dataSorted;
}

/**
 * Sets the current classify vector
 * @param vect the vector being set
*/
void CommandData::setClassifyVect(vector<Database> vect) {
    m_classifyVect = vect;
}

/**
 * Sets the current unclassified vector
 * @param vect the vector being set
*/
void CommandData::setUnClassifyVect(vector<Database> vect) {
    m_unClassifyVect = vect;
}

/**
 * Returns the classify vector
 * @return the classify vector
*/
vector<Database>& CommandData::getClassifyVect() {
    return m_classifyVect;
}

/**
 * Returns the unclassified vector
 * @return the unclassified vector
*/
vector<Database>& CommandData::getUnClassifyVect() {
    return m_unClassifyVect;
}

/**
 * Clears the current classify vector
*/
void CommandData::clearClassifyVect() {
    m_classifyVect.clear();
}

/**
 * Clears the current unclassified vector
*/
void CommandData::clearUnClassifyVect() {
    m_unClassifyVect.clear();
}