#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "VectorCheck.h"
#include "RecieveCheckServer.h"
#include <iostream>

using namespace std;


/**
 * The function checks if there is an exponent in the string and if it is valid
 * @param s the string being checked
 * @return returns true if there is no exponent or if it is valid
*/
bool RecieveCheckServer::exponentCheck(string s) {
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
 * The function checks the vector for it's validity and fixes it
 * @param s the vector being checked
 * @return the fixed string
*/
string RecieveCheckServer::stringCheckAndFix(string s) {
    string temp, fixed = "";
    stringstream SStr(s);
    //Splits the string based on the spaces in it
    while (getline(SStr, temp, ' ')) {
        int tlen = temp.length();
        //After cutting the string, if the first char of it is not a digit, dot or a minus, throws an exception
        if (!isdigit(temp[0]) && temp[0] != '-' && temp[0] != '.') throw exception();
        //If it is a dot alone, add zeros
        if (tlen == 1 && temp[0] == '.') {
            temp = "0.0";
            fixed.append(" " + temp);
            continue;
        }
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
                fixed.append(" " + temp);
                continue;
            }
            //Checks if there is only one dot, if it exists
            bool pointFlag = false;
            int j = 0;
            for (j; j < tlen; j++) {
                if (temp[j] == '.') {
                    //If there are more than one dot, throws an exception
                    if (pointFlag) throw exception();
                    else {
                        pointFlag = true;
                        continue;
                    }
                } else {
                    if (temp[j] == '-' && j == 0) j++;
                    //If a part of the string is not a dot, makes sure it is a digit or a valid exponent
                    if (!isdigit(temp[j])) throw exception();
                }
            }
        }
        //Adds the value to the vector
        fixed.append(" " + temp);
    }
    //Cuts the first space
    fixed = fixed.substr(1, fixed.length() - 1);
    return fixed;
}

/**
 * The function takes a string representing an int, checking it and converting it to int
 * @param knum the string being checked
 * @return the converted int
*/
int RecieveCheckServer::numCheck(string knum) {
    int klen = knum.length();
    int i;
    //Iterates through the character, if one is not a digit, sends an error and closes the program
    for (i = 0; i < klen; i++) if (!isdigit(knum[i])) throw exception();
    //If it contains only numbers, define the integer k by it
    int k = stoi(knum);
    //If it is 0, sends an error and closes the program(should be a natural number that is higher than 0)
    if (k == 0) throw exception();
    return k;
}

/**
 * The function checks where is the distance parameter taken from the client
 * @param input the string being checked
 * @return the location of the distance parameter in the string
*/
int RecieveCheckServer::distCheck(string input) {
    int len = input.length();
    //If the string is too short, throws exception
    if (len < 3) throw exception();
    //Counts the number of spaces
    int numSpaces = count(input.begin(), input.end(), ' ');
    //If there are not enough spaces, throws exception
    if (numSpaces < 2) throw exception();
    //Iterates from the end to the last space and counts backwards
    string::iterator it = input.end() - 1;
    while (it[0] != ' ') {
        it--;
        len--;
    }
    //Goes one back
    it--;
    len--;
    //Iterates to the second-to-last space
    while (it[0] != ' ') {
        it--;
        len--;
    }
    //Returns the location of the first character afterwards
    return len;
}

/**
 * The function cuts all extra spaces from the string input
 * @param input the string being fixed
 * @return the fixed string
*/
string RecieveCheckServer::cutSpaces(string input) {
    stringstream SStr(input);
    string temp, fixed = "";
    while (getline(SStr, temp, ' ')) {
        //Checks if the string is empty, if it is continue the loop
        if (!temp.length()) continue;
        //Checks for excessive spaces in the beginning of the object, and cuts it accordingly
        int j = 0;
        for (j = 0; j < temp.length(); j++) if (temp[j] != ' ') break;
        if (j) temp = temp.substr(j, temp.length() - j);
        fixed.append(" " + temp);
    }
    fixed = fixed.substr(1, fixed.length() - 1);
    return fixed;
}

/**
 * The function checks the parameters inserted from the client
 * @param inputParam the checked parameters
 * @return the K number parameter
*/
string RecieveCheckServer::paramCheck(string inputParam) {
    stringstream SStr(inputParam);
    string temp, knum;
    int counter = 0;
    //Counts the number of parameters
    while (getline(SStr, temp, ' ')) { 
        counter++;
        knum = temp;
    }
    //If it's correct, returns the K number
    if (counter == 2) {
        return knum;
    }
    //If not, throws an exception
    throw exception();
}

/**
 * The function checks validation of the ip
 * @param inputParam the checked parameters
 * @return true if the string is valid , false if not
*/
bool RecieveCheckServer::checkIP(string inputParam) {
    stringstream SStr(inputParam);
    string temp, knum;
    int byteIp;
    int counter = 0;
    //Counts the number of parameters
    while (getline(SStr, temp, '.')) { 
        if(counter == 4){
            return false;
        }
        try
        {
            int tlen = temp.length();
            int i;
            //Iterates through the character, if one is not a digit, sends an error and closes the program
            for (i = 0; i < tlen; i++) if (!isdigit(temp[i])) throw exception();
            //If it contains only numbers, define the integer k by it
            byteIp = stoi(temp);
        }
        catch(const std::exception& e)
        {
            return false;
        }
        if (byteIp > 255)
        {
            return false;
        }
        counter++;
    }
    if (counter != 4) return false;
    //If valid return true 
    return true;
}


/**
* constractor - splits the information in the string to k, distance type and vector
* @param recieve type string.
*/
RecieveCheckServer::RecieveCheckServer(string line){
    stringstream recieve(line);
    string subStringRecieve;
    vector<string> recieveList;
    while(getline(recieve, subStringRecieve, ' '))
    {
        recieveList.push_back(subStringRecieve);
    }
    if(recieveList.size() < 3) {
        k = 0;
        distance = "";
    }
    try
    {
        string recieveK = recieveList.back();
        recieveList.pop_back();
        k = stoi(recieveK);
        distance = recieveList.back();
        recieveList.pop_back();
        int sizeVector = recieveList.size();
        for (int i = 0; i < sizeVector; i++)
        {
            vect.push_back(stod(recieveList[i]));
        }
    }
    catch(const exception& e)
    {
        k = 0;
        distance = "";
    }
}
/**
* get k, if k = 0 the string invalid.
* @return - k - the last word of the string
*/
int RecieveCheckServer::getRecieveK(){
    return k;
}
/**
* get distance type, if return null the string invalid.
* @return - distance type.
*/
string RecieveCheckServer::getDistanceOption(){
    return distance;
}
/**
* get vector.
* @return - vector type double.
*/
vector<double> RecieveCheckServer::getVector(){
    return vect;
}
