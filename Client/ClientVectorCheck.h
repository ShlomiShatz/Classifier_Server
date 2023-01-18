#ifndef CLIENTVECTORCHECK_H_
#define CLIENTVECTORCHECK_H_

#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * The class incharge of checking the client's input validity
*/
class ClientVectorCheck {
private:

    /**
     * The function checks if there is an exponent in the string and if it is valid
     * @param s the string being checked
     * @return returns true if there is no exponent or if it is valid
    */
    static bool exponentCheck(string s);

public:

    /**
     * The function checks the vector for it's validity and fixes it
     * @param s the vector being checked
     * @return the fixed string
    */
    static string stringCheckAndFix(string s);

    /**
     * The function takes a string representing an int, checking it and converting it to int
     * @param knum the string being checked
     * @return the converted int
    */
    static int kCheck(string knum);

    /**
     * The function checks where is the distance parameter taken from the client
     * @param input the string being checked
     * @return the location of the distance parameter in the string
    */
    static int distCheck(string input);

    /**
     * The function cuts all extra spaces from the string input
     * @param input the string being fixed
     * @return the fixed string
    */
    static string cutSpaces(string input);

    /**
     * The function checks the parameters inserted from the client
     * @param inputParam the checked parameters
     * @return the K number parameter
    */
    static string paramCheck(string inputParam);

    /**
     * The function checks validation of the if
     * @param inputParam the checked parameters
     * @return true if the string is valid , false if not
    */
    static bool checkIP(string inputParam);
};

#endif
