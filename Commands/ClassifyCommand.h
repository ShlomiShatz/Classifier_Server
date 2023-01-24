#ifndef CLASSIFYCOMMAND_H_
#define CLASSIFYCOMMAND_H_

#include <string>
#include <vector>
#include "../IOs/DefaultIO.h"
#include "Command.h"
#include "../Server/Database.h"

using namespace std;

/**
 * The class that incharge of classifying the vectors
*/
class ClassifyCommand : public Command {
private:

    /**
    * The function calculates the distance from a vector to the classifiers
    * @param vect the vector being calculated
    */
    void calcDistance(vector<double> vect);

    /**
    * The function get the type of the K neares neighbors
    * @return the classification type
    */
    string getType();

public:
	
    /**
    * Default constructor
    */
    ClassifyCommand();

    /**
    * The constructor of the class
    * @param io the DefaultIO pointer for this command
    * @param cd the full data structure of this program
    */
    ClassifyCommand(DefaultIO* io, CommandData* cd);

    /**
    * The function that runs this command
    */
	void execute();

    /**
    * The function returns the description of this command
    * @return the description
    */
    string getDescription();
};

#endif