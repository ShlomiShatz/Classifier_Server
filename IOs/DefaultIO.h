#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_

#include <string>

using namespace std;

/**
 * The default IO abstract class
*/
class DefaultIO {
	
public:

    /**
     * The function incharges of reading data
     * @return the data that was read
    */
	virtual string read() = 0;

    /**
     * The function incharges of writing data
     * @param s the string being written
    */
    virtual void write(string) = 0;
    
};

#endif