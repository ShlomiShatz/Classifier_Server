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

/**
 * The class incharge of communicating with the client through command line
*/
class CLI {
private:

	//The command vector
	vector<Command*> m_coms;
	//The default IO object
	DefaultIO *m_dio;
	//The data structure containing all the information
	CommandData m_currentData;
	//The commands being stored in the vector
	UploadUnclassCommand m_upl;
    AlgoSettingCommand m_alg;
    ClassifyCommand m_cla;
    DisplayResultsCommand m_disp;
    DownloadResultsCommand m_downl;
    ExitCommand m_exitc;

public:
	
	/**
	* The constructor of the class
	* @param dio the DefaultIO pointer for this CLI
	*/
	CLI(DefaultIO* dio);

	/**
	* The function that starts the CLI
	*/
	void start();

	/**
	* The function prints the menu of the CLI
	* @return the menu
	*/
	string printMenu();
    
};

#endif