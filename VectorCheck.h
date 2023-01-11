#ifndef VECTORCHECK_H_
#define VECTORCHECK_H_

#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * The class incharge of checking vectors' validity and converting it to double if needed
*/
class VectorCheck {
private:

    /**
     * The function checks if there is an exponent in the string and if it is valid
     * @param s the string being checked
     * @return returns true if there is no exponent or if it is valid
    */
    static bool exponentCheck(string s);

public:

    /**
     * The function checks the validity of a given string and converts it to a double vector
     * @param s the string being checked and converted
     * @return the returned double vector
    */
    static vector<double> stringToVector(string s);

    /**
     * The function checks the validity of a given string vector and converts it to a double vector
     * @param s the string vector being checked and converted
     * @return the returned double vector
    */
    static vector<double> stringVectToVector(vector<string> s);

    /**
     * The function takes a string representing an int, checking it and converting it to int
     * @param num the string being checked
     * @return the converted int
    */
    static int portCheck(string num);
};

#endif
