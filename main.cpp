#include <iostream>
#include "BaseFactory.hpp"
#include "lab04include.hpp"


int main(int argc,char** argv){
    
   //example of how parse() might look like
   
   //Base* userTree = BaseFactory::parse(argv, argc);
   //Base* userTree = BaseFactory().parse(argv, argc);
   BaseFactory* base = new BaseFactory();
   Base* userTree = base->parse(argv, argc);

   if (userTree != nullptr){
   cout << userTree->stringify() << endl;
   cout << userTree->evaluate() << endl;
   }
   else {
       cout << endl << "Error In User Input" << endl;
    }

    return 0;
}

