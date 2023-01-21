#include <string>
#include "../IOs/DefaultIO.h"
#include "Command.h"

using namespace std;

Command::Command(string desc, DefaultIO *defio) : m_description(desc), m_dio(defio) {}
string Command::getDescription() { 
    return m_description;
}