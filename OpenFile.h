#ifndef OPENFILE_H_
#define OPENFILE_H_

#include <vector>
#include <string>
#include "Database.h"

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
    * The function used to create a Database vector, based on the file name
    * @return the created Database vector
    */
    vector<Database> CreateDatabase();
};
#endif