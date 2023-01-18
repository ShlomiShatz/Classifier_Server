#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Server/Database.h"
#include "OpenFile.h"


/**
* Constructor
* @param name - the path of the file.
*/
OpenFile::OpenFile(string name){
    fileName = name;
}
/**
 * The function used to create a Database vector, based on the file name
 * @param fileName the name of the file(expected to be in the same folder)
 * @return the created Database vector
*/
vector<Database> OpenFile::CreateDatabase() {
    vector<string> row;
    vector<Database> vect;
    string line, word;
    bool didPassFirst = false;
    int rowSize = 0;
    //Opens the file
    fstream f(fileName, ios::in);
    //If it was indeed opened(thus it exists), read through it
    if(f.is_open()) {
        //The loop that reads from the file, line by line
        while(getline(f, line)) {
            //Clears the row variable
            row.clear();
            stringstream str(line);
            //Iterates through the row that was read, deviding it by commas
            while(getline(str, word, ',')) {
                //If a the string has anything in it, push it to the vector
                if (word.length() != 0) row.push_back(word);
                //If it is empty, push 0.0
                else {
                    f.close();
                    throw 0;
                }
            }
            //If it is not the first vector, compare its size. If it is wrong - throw an exception
            if (didPassFirst) {
                if (row.size() != rowSize) {
                    f.close();
                    throw 0;
                }
            //If it is the first vector, define the size being compared by it
            } else {
                rowSize = row.size();
                didPassFirst = true;
                //If it is empty, throw an exception
                if (!rowSize) {
                    f.close();
                    throw 0;
                }
            }
            //Constructs a Database from the row vector
            Database db(row);
            //Pushes it to the vector
            vect.push_back(db);
        }
    //If the file failed to open, throw an exception
    } else {
        f.close();
        throw 0;
    }
    //Close the file at the end and return the completed vector
    f.close();
    if (vect.size() == 0) throw 0;
    return vect;
}
