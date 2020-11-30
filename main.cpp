#include <iostream>
#include "BaseFactory.hpp"

int main(int argc,char** argv){
    
   //example of how parse() might look like
   Base* userTree = new parse(argv,argc);
   userTree->stringify();
   userTree->evaluate();
}

