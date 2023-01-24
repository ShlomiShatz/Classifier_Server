#ifndef OPENFILE_H_
#define OPENFILE_H_

#include <vector>
#include <string>
#include "Server/Database.h"

using namespace std;

/**
 * A class incharge of calculating the Manhattan distance, inherets from the Distance class
*/
class OpenFile {
private:
    string fileName;
public:
    /**
    * Constructor
    * @param name - the path of the file.
    */
    OpenFile(string name);


    /**
     * The funcion reads a file and converts it to string
     * @return the string converted
    */
    string ClientFile();
};
#endif