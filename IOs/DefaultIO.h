#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_

#include <string>

using namespace std;

class DefaultIO {
	
public:
	
	virtual string read();

    virtual void write(string);

    ~DefaultIO() {}
    
};

#endif