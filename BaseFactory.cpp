#include "BaseFactory.hpp"

Base* BaseFactory::parse(char** input,int length)
{
  //Intended not as real definition
  //Only layout
  
  //sstream
  for(int i= 0; i < length;i++){
      if(input == "*"){
        Mult(this->left,this->right);
      } 
      else if(input == "/"){
        Div(this->left,this->right);
      }
      else if(input == "+"{
        Add(this->left,this->right);
      }
      else if(input == "-"){
        Sub(this->left,this->right);
      }
      else{
        cout<<"Invalid Input"<<endl;
      }
   }  
  return this->root->evaluate()
}

