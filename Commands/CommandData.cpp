#include <string>
#include "CommandData.h"


CommandData::CommandData() {
    m_currentK = 5;
    m_maxK = -1;
    m_matric = "AUC";
    m_dataAlreadyUpload = false;
    m_dataSorted = false;
    m_classifyVect.clear();
    m_unClassifyVect.clear();
}

void CommandData::setCurrentK(int k) {
    m_currentK = k;
}

void CommandData::setMaxK(int k) {
    m_maxK = k;
}

void CommandData::setMatric(string s) {
    m_matric = s;
}

void CommandData::setDataUpload(bool b) {
    m_dataAlreadyUpload = b;
}

void CommandData::setDataSort(bool b) {
    m_dataSorted = b;
}

int CommandData::getCurrentK() {
    return m_currentK;
}

int CommandData::getMaxK() {
    return m_maxK;
}

string CommandData::getMatric() {
    return m_matric;
}

bool CommandData::getDataUpload() {
    return m_dataAlreadyUpload;
}

bool CommandData::getDataSort() {
    return m_dataSorted;
}

void CommandData::setClassifyVect(vector<Database> vect) {
    m_classifyVect = vect;
}

void CommandData::setUnClassifyVect(vector<Database> vect) {
    m_unClassifyVect = vect;
}

vector<Database>& CommandData::getClassifyVect() {
    return m_classifyVect;
}

vector<Database>& CommandData::getUnClassifyVect() {
    return m_unClassifyVect;
}

void CommandData::clearClassifyVect() {
    m_classifyVect.clear();
}

void CommandData::clearUnClassifyVect() {
    m_unClassifyVect.clear();
}