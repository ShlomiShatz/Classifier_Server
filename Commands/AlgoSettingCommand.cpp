#include <string>
#include "AlgoSettingCommand.h"

using namespace std;

AlgoSettingCommand::AlgoSettingCommand() {
    Command::m_description = "algorithm settings";
    k = 5;
    distanceMetric = "AUC";
}
void AlgoSettingCommand::execute() {
    
    
}
    
