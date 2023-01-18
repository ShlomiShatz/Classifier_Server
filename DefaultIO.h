#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_

#include <string>

using namespace std;

class DefaultIO {
	
public:
	
	virtual string read() = 0;

    virtual void write(string) = 0;
    
};

#endif