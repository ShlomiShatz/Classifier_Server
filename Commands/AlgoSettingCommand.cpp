#include <string>
#include "AlgoSettingCommand.h"

using namespace std;



AlgoSettingCommand::AlgoSettingCommand() : description("algorithm settings") {
    k = 5;
    distanceMetric = "AUC";
}
void AlgoSettingCommand::execute() {
    string data = dio.read();
    
}
    
