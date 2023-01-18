#include <string>
#include <iostream>
#include "StandartIO.h"

using namespace std;

string StandartIO::read() {
    string input;
    //Getting the input from the user
    getline(cin, input);
    return input;
}

void StandartIO::write(string s) {
    cout << s << endl;
}