#include <string>

class DefaultIO {
	
public:
	
	virtual string read() = 0;

    virtual void write(string) = 0;
    
};
