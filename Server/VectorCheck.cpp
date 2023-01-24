#include <vector>
#include <string>
#include <sstream>
#include "VectorCheck.h"

using namespace std;

/**
 * The function checks if there is an exponent in the string and if it is valid
 * @param s the string being checked
 * @return returns true if valid and false if no exponent
*/
bool VectorCheck::exponentCheck(string s) {
    string sub;
    //Finds the location of an 'e' or 'E' in the string
    int eloc = s.find('e', 0);
    int Eloc = s.find('E', 0);
    //If it exists, checks its validity
    if (eloc > 0) {
        //Checks the validity of the number after the exponent
        sub = s.substr(eloc + 1, s.length() - eloc - 1);
        int m = 0;
        int subSize = sub.size();
        if (sub[0] == '-' || sub[0] == '+') m++;
        //If there are more then 3 digits after the exponent, returns false
        if (subSize > (m + 3)) return false;
        //Checks for anything that is not a digit
        for (m; m < subSize; m++) if (!isdigit(sub[m])) return false;
        double subNum = stod(sub);
        //If the number is bigger than 250 or smaller than 250, returns false
        if (subNum > 250 || subNum < -250) return false;
        return true;
    } else if (Eloc > 0) {
        //Checks the validity of the number after the exponent
        sub = s.substr(Eloc + 1, s.length() - Eloc - 1);
        int m = 0;
        int subSize = sub.size();
        if (sub[0] == '-' || sub[0] == '+') m++;
        //If there are more then 3 digits after the exponent, returns false
        if (subSize > (m + 3)) return false;
        //Checks for anything that is not a digit
        for (m; m < subSize; m++) if (!isdigit(sub[m])) return false;
        double subNum = stod(sub);
        //If the number is bigger than 250 or smaller than 250, returns false
        if (subNum > 250 || subNum < -250) return false;
        return true;
    }
    //If it does not exists return false
    return false;
}
/**
 * The function checks the validity of a given string and converts it to a string vector
 * @param s the string being checked and converted
 * @return the returned string vector
 */
vector<string> VectorCheck::stringToVectorString(string s){
    string temp;
    vector<string> vect;
    stringstream SStr(s);
    //Splits the string based on the spaces in it
    while (getline(SStr, temp, ',')) {
        //Checks if the string is empty, if it is continue the loop
        if (!temp.length()) continue;
        //Checks for excessive spaces in the beginning of the object, and cuts it accordingly
        int j = 0;
        int tlen = temp.length();
        //After cutting the string, if the first char of it is not a digit, dot or a minus, throws an exception
        if (!isdigit(temp[0]) && temp[0] != '-' && temp[0] != '.') throw exception();
        //If it is a dot alone, add zeros
        if (tlen == 1 && temp[0] == '.') temp = "0.0";
        //if the temp is '-' only, throws an exception
        if (tlen == 1 && temp[0] == '-') throw exception();
        //If there are point and minus combined, throws an exception
        if (tlen > 1) if (temp[0] == '-' && temp[1] == '.') throw exception();
        //Checks that the number is not too big
        if (tlen > 250) throw exception();
        //If there is more than one digit in the number, checks its validity
        if (tlen > 1) {
            //If the last char is not a digit, throws an exception
            if (!isdigit(temp[tlen - 1]) && temp[tlen - 1] != '.') throw exception();
            if (exponentCheck(temp)) {
                //Adds to value to the vector
                vect.push_back(temp);
                continue;
            }
            //Checks if there is only one dot, if it exists
            bool pointFlag = false;
            for (j = 0; j < tlen; j++) {
                if (temp[j] == '.') {
                    //If there are more than one dot, throws an exception
                    if (pointFlag) throw exception();
                    else {
                        pointFlag = true;
                        continue;
                    }
                } else {
                    //If a part of the string is not a dot, makes sure it is a digit or a valid exponent
                    if (!isdigit(temp[j])) {
                        if (tlen > 3 && j == (tlen - 3) && (temp[j] == 'e' || temp[j] == 'E')){
                            if (temp[++j] == '-') {
                                j++;
                                continue;
                            }
                        }
                        throw exception();
                    }
                }
            }
        }
        //Adds to value to the vector
        vect.push_back(temp);
    }
    return vect;
}
/**
 * The function checks the validity of a given string and converts it to a double vector
 * @param s the string being checked and converted
 * @return the returned double vector
*/
vector<double> VectorCheck::stringToVector(string s) {
    string temp;
    vector<double> vect;
    stringstream SStr(s);
    //Splits the string based on the spaces in it
    while (getline(SStr, temp, ' ')) {
        //Checks if the string is empty, if it is continue the loop
        if (!temp.length()) continue;
        //Checks for excessive spaces in the beginning of the object, and cuts it accordingly
        int j = 0;
        for (j = 0; j < temp.length(); j++) if (temp[j] != ' ') break;
        if (j) temp = temp.substr(j, temp.length() - j);
        int tlen = temp.length();
        //After cutting the string, if the first char of it is not a digit, dot or a minus, throws an exception
        if (!isdigit(temp[0]) && temp[0] != '-' && temp[0] != '.') throw exception();
        //If it is a dot alone, add zeros
        if (tlen == 1 && temp[0] == '.') temp = "0.0";
        //if the temp is '-' only, throws an exception
        if (tlen == 1 && temp[0] == '-') throw exception();
        //If there are point and minus combined, throws an exception
        if (tlen > 1) if (temp[0] == '-' && temp[1] == '.') throw exception();
        //Checks that the number is not too big
        if (tlen > 250) throw exception();
        //If there is more than one digit in the number, checks its validity
        if (tlen > 1) {
            //If the last char is not a digit, throws an exception
            if (!isdigit(temp[tlen - 1]) && temp[tlen - 1] != '.') throw exception();
            if (exponentCheck(temp)) {
                //Adds to value to the vector
                vect.push_back(stod(temp));
                continue;
            }
            //Checks if there is only one dot, if it exists
            bool pointFlag = false;
            for (j = 0; j < tlen; j++) {
                if (temp[j] == '.') {
                    //If there are more than one dot, throws an exception
                    if (pointFlag) throw exception();
                    else {
                        pointFlag = true;
                        continue;
                    }
                } else {
                    //If a part of the string is not a dot, makes sure it is a digit or a valid exponent
                    if (!isdigit(temp[j])) {
                        if (tlen > 3 && j == (tlen - 3) && (temp[j] == 'e' || temp[j] == 'E')){
                            if (temp[++j] == '-') {
                                j++;
                                continue;
                            }
                        }
                        throw exception();
                    }
                }
            }
        }
        //Adds to value to the vector
        vect.push_back(stod(temp));
    }
    return vect;
}

/**
 * The function checks the validity of a given string vector and converts it to a double vector
 * @param s the string vector being checked and converted
 * @return the returned double vector
*/
vector<double> VectorCheck::stringVectToVector(vector<string> s) {
    vector<double> vect;
    //Iterates through the string vector
    for (auto& elem : s){
        //Checks for excessive spaces in the beginning of the object, and cuts it accordingly
        int j = 0;
        for (j = 0; j < elem.length(); j++) if (elem[j] != ' ') break;
        if (j) elem = elem.substr(j, elem.length() - j);
        int elen = elem.length();
        //After cutting the string, if the first char of it is not a digit, dot or minus, throws an exception
        if (!isdigit(elem[0]) && elem[0] != '-' && elem[0] != '.') throw exception();
        //If it is a dot alone, add zeros
        if (elen == 1 && elem[0] == '.') elem = "0.0";
        //if the elem is '-', throws an exception
        if (elen == 1 && elem[0] == '-') throw exception();
        //If there are point and minus combined, throws an exception
        if (elen > 1) if (elem[0] == '-' && elem[1] == '.') throw exception();
        //Checks that the number is not to big
        if (elen > 250) throw exception();
        //If there is more than one digit in the number, checks its validity
        if (elen > 1) {
            //If the last char is not a digit, throws an exception
            if (!isdigit(elem[elen - 1]) && elem[elen - 1] != '.') throw exception();
            if (exponentCheck(elem)) {
                //Adds to value to the vector
                vect.push_back(stod(elem));
                continue;
            }
            //Checks if there is only one point, if it exists
            bool pointFlag = false;
            for (j = 0; j < elen; j++) {
                if (elem[j] == '.') {
                    //If there are more than one dot, throws an exception
                    if (pointFlag) throw exception();
                    else {
                        pointFlag = true;
                        continue;
                    }
                } else {
                    if (elem[j] == '-' && j == 0) j++;
                    //If a part of the string is not a dot, makes sure it is a digit or a valid exponent
                    if (!isdigit(elem[j])) throw exception();
                }
            }
        }
        //Adds to value to the vector
        vect.push_back(stod(elem));
    }
    return vect;
}

/**
 * The function takes a string representing an int, checking it and converting it to int
 * @param num the string being checked
 * @return the converted int
*/
int VectorCheck::portCheck(string num) {
    int len = num.length();
    int i;
    //Iterates through the character, if one is not a digit, sends an error and closes the program
    for (i = 0; i < len; i++) if (!isdigit(num[i])) throw exception();
    //If it contains only numbers, define the integer k by it
    int k = stoi(num);
    //If it is 0, sends an error and closes the program(should be a natural number that is higher than 0)
    if (k > 65535 || k < 1024) throw exception();
    return k;
}