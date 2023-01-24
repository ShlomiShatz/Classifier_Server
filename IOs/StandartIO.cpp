#include <string>
#include <iostream>
#include "StandartIO.h"

using namespace std;

/**
 * Default constructor
*/
StandartIO::StandartIO() {}

/**
 * Default destructor
*/
StandartIO::~StandartIO() {}

/**
 * The function incharge of taking input from commandline
 * @return the input taken
*/
string StandartIO::read() {
    string input;
    //Getting the input from the user
    getline(cin, input);
    return input;
}

/**
 * The function incharge of printing data to the commandline
 * @param s the data printed
*/
void StandartIO::write(string s) {
    cout << s << endl;
}