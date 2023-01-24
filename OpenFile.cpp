#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Server/Database.h"
#include "OpenFile.h"

using namespace std;

/**
* Constructor
* @param name - the path of the file.
*/
OpenFile::OpenFile(string name): fileName(name) {}

string OpenFile::ClientFile() {
    ifstream f(fileName);
    if (!f.is_open()) throw exception();
    stringstream buffer;
    buffer << f.rdbuf();
    if (f.is_open()) f.close();
    return buffer.str();
}
