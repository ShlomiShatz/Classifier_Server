#ifndef CLI_H_
#define CLI_H_

#include "Command.h"
#include "CommandData.h"
#include "../IOs/DefaultIO.h"
#include "UploadUnclassCommand.h"
#include "AlgoSettingCommand.h"
#include "ClassifyCommand.h"
#include "DisplayResultsCommand.h"
#include "DownloadResultsCommand.h"
#include "ExitCommand.h"
#include <vector>

using namespace std;

class CLI {
private:

	vector<Command*> m_coms;
	DefaultIO *m_dio;
	CommandData m_currentData;
	UploadUnclassCommand m_upl;
    AlgoSettingCommand m_alg;
    ClassifyCommand m_cla;
    DisplayResultsCommand m_disp;
    DownloadResultsCommand m_downl;
    ExitCommand m_exitc;

public:
	
	CLI(DefaultIO* dio);
	void start();
	string printMenu();
    
};

#endif