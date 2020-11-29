#ifndef __BASE_FACTORY__
#define __BASE_FACTORY__

#include <iostream>
#include <string>
#include <sstream>

class BaseFactory:public Base
{
    private:
    Base *root = nullptr;

    public:
    
    Base* parse(char** input,int length);

};

#endif //__BASE_FACTORY__
