#include <string>
#include "CLI.h"
#include <vector>
#include "Command.h"
#include "../IOs/DefaultIO.h"
#include "UploadUnclassCommand.h"
#include "AlgoSettingCommand.h"
#include "ClassifyCommand.h"
#include "DisplayResultsCommand.h"
#include "DownloadResultsCommand.h"
#include "ExitCommand.h"

#include <iostream>//**********************************************************************

using namespace std;


CLI::CLI(DefaultIO* dio) : m_dio(dio) {
    m_upl = UploadUnclassCommand(dio, &m_currentData);
    m_alg = AlgoSettingCommand(dio, &m_currentData);
    m_cla = ClassifyCommand(dio, &m_currentData);
    m_disp = DisplayResultsCommand(dio, &m_currentData);
    m_downl = DownloadResultsCommand(dio, &m_currentData);
    m_exitc = ExitCommand(dio, &m_currentData);
    m_coms.push_back(&m_upl);
    m_coms.push_back(&m_alg);
    m_coms.push_back(&m_cla);
    m_coms.push_back(&m_disp);
    m_coms.push_back(&m_downl);
    m_coms.push_back(&m_exitc);
}

CLI::~CLI() {
    // for(map<string, Distance*>::iterator it = m_typeDistance.begin(); it!=m_typeDistance.end(); it++) {
    //     delete[] it->second;
    //     m_typeDistance.erase(it);
    // }
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
    menu.append("\n8. exit|||");
    return menu;
}

void CLI::start() {
    while (true) {
        m_dio->write(printMenu());
        // cout << "-200" << endl;//****************************************************
        string option = m_dio->read();
        // cout << "-201" << endl;//****************************************************
        if (option == "1") {
            // cout << "-213" << endl;//****************************************************
            m_coms[0]->execute();
            // cout << "-214" << endl;//****************************************************
        } else if (option == "2") {
            // cout << "-223" << endl;//****************************************************
            m_coms[1]->execute();
            // cout << "-224" << endl;//****************************************************
        } else if (option == "3") {
            // cout << "-235" << endl;//****************************************************
            m_coms[2]->execute();
            // cout << "-236" << endl;//****************************************************
        } else if (option == "4") {
            // cout << "-245" << endl;//****************************************************
            m_coms[3]->execute();
            // cout << "-247" << endl;//****************************************************
        } else if (option == "5") {
            // cout << "-274" << endl;//****************************************************
            m_coms[4]->execute();
            // cout << "-276" << endl;//****************************************************
        } else if (option == "8") {
            m_coms[5]->execute();
            break;
        } else {
            m_dio->write("invalid input");
            continue;
        }
    }
}
    