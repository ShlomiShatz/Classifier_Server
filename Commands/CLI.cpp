#include <string>
#include "CLI.h"
#include <vector>
#include "Command.h"
#include "UploadUnclassCommand.h"
#include "AlgoSettingCommand.h"
#include "ClassifyCommand.h"
#include "DisplayResultsCommand.h"
#include "DownloadResultsCommand.h"

using namespace std;


CLI::CLI() {
    coms.push_back(UploadUnclassCommand());
    coms.push_back(AlgoSettingCommand());
    coms.push_back(ClassifyCommand());
    coms.push_back(DisplayResultsCommand());
    coms.push_back(DownloadResultsCommand());
}

void CLI::start() {
    
}
    
