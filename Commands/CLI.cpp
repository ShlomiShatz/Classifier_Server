#include <string>
#include "CLI.h"
#include <vector>
#include "Command.h"
#include "UploadUnclassCommand.h"
#include "AlgoSettingCommand.h"
#include "ClassifyCommand.h"
#include "DisplayResultsCommand.h"
#include "DownloadResultsCommand.h"
#include "ExitCommand.h"

#include <iostream>//*********************************************************************************

using namespace std;


CLI::CLI(DefaultIO* dio) : m_dio(dio) {
    currentData = new CommandData();
    m_coms.push_back(new UploadUnclassCommand(dio, currentData));
    m_coms.push_back(new AlgoSettingCommand(dio, currentData));
    m_coms.push_back(new ClassifyCommand(dio, currentData));
    m_coms.push_back(new DisplayResultsCommand(dio, currentData));
    m_coms.push_back(new DownloadResultsCommand(dio, currentData));
    m_coms.push_back(new ExitCommand(dio, currentData));
}

string CLI::printMenu() {
    string menu = "Welcome to the KNN Classifier Server. Please Choose an option:";
    int i;
    for (i = 0; i < m_coms.size() - 1; i++) {
        menu.append("\n");
        menu.append(to_string(i + 1));
        menu.append(". ");
        menu.append(m_coms[i]->getDescription());
    }
    menu.append("\n8. exit");
    return menu;
}

void CLI::start() {
    while (true) {
        m_dio->write(printMenu());
        string option = m_dio->read();
        if (option == "1") {
            m_coms[0]->execute();

            // int maxK = (((UploadUnclassCommand*) m_coms[0]) ->getMaxK());
            // ((AlgoSettingCommand*)m_coms[1]) -> setMaxK(maxK);
            // ((ClassifyCommand*)m_coms[2]) -> setClassifyVector(((UploadUnclassCommand*) m_coms[0]) ->getClassifyVect());
            // ((ClassifyCommand*)m_coms[2]) -> setTestVector(((UploadUnclassCommand*) m_coms[0]) ->getUnClassifyVect());
            // ((DownloadResultsCommand*)m_coms[4]) -> setDataAlreadyUpload(true);
            // ((DisplayResultsCommand*)m_coms[3]) ->  setDataAlreadyUpload(true);
        } else if (option == "2") {
            m_coms[1]->execute();
            // ((ClassifyCommand*)m_coms[2]) -> setK(((AlgoSettingCommand*)m_coms[1])->getK());
            // ((ClassifyCommand*)m_coms[2]) -> setDistanceMetrix(((AlgoSettingCommand*)m_coms[1])->getDistanceMetric());
        } else if (option == "3") {
            m_coms[2]->execute();
            // ((DisplayResultsCommand*)m_coms[3]) -> setTestVector(((ClassifyCommand*)m_coms[2])->getTestVector());
            // ((DownloadResultsCommand*)m_coms[4]) -> setTestVector(((ClassifyCommand*)m_coms[2])->getTestVector());
            // ((DownloadResultsCommand*)m_coms[4]) -> setDataSorted(true);
            // ((DisplayResultsCommand*)m_coms[3]) ->  setDataSorted(true);
        } else if (option == "4") {
            m_coms[3]->execute();
        } else if (option == "5") {
            m_coms[4]->execute();
        } else if (option == "8") {
            m_coms[5]->execute();
            break;
        } else {
            m_dio->write("invalid input");
            continue;
        }
    }

    
}
    