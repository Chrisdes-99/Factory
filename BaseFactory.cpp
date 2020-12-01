#include "BaseFactory.hpp"
#include "lab04include.hpp"
#include <cctype>

Base* BaseFactory::parse(char** input,int length)
{
  //Intended not as real definition
  //Only layout
  //sstream 
  Base* leftUser = nullptr;
  Base* rightUser = nullptr;
  Base* prevBase = nullptr;

  Base* pow = nullptr;
  Base* mult = nullptr;
  Base* div = nullptr;
  Base* add = nullptr;
  Base* sub = nullptr;

  int num = 0;
  double dNum(0);

  for(int i= 1; i < length; i = i){
     // 1.check if first is digit
      num = (*input[i]);
      if (isdigit(num)) {
          dNum = stod(input[i]);
          leftUser = new Op(dNum);
          // 2.check if next is multi
          if ((*input[i+1]) == '*') {
              num = (*input[i+2]);
              // 3.check if next + 1 is pow
              if ((*input[i+2]) == '*') {
               
                // 4.check if next + 2 is number
                num = (*input[i+3]);
                if (isdigit(num)) {
                    dNum = stod(input[i+3]);
                    rightUser = new Op(dNum);
                    pow = new Pow(leftUser, rightUser);
                    prevBase = pow;
                    i = i + 4;
                }
                else {
                    cout << "Invalid 1" << endl;
                    return nullptr;
                }
               num = (*input[i+2]); 
              }

              // 3.check if next + 1 is number
              //num = (*input[i+2]);
              else if (isdigit(num)) {
                dNum = stod(input[i+2]);
                rightUser = new Op(dNum);
                mult = new Mult(leftUser, rightUser);
                prevBase = mult;
                i = i + 3;
              }
              else {
                  cout << "Invalid 2" << endl;
                  return nullptr;
              }
          }
          // 2.check if next is division
          else if ((*input[i+1] == '/')) {
              num = (*input[i+2]);
              // 3.
              if (isdigit(num)) {
                  dNum = stod(input[i+2]);
                  rightUser = new Op(dNum);
                  div = new Div(leftUser, rightUser);
                  prevBase = div;
                  i = i + 3;
              }
              else {
                  cout << "Invalid 3" << endl;
                  return nullptr;
              }
          }

          // 2.check if next is add
          else if ((*input[i+1]) == '+') {
              num = (*input[i+2]);   
              //3. 
              if (isdigit(num)) {
                  dNum = stod(input[i+2]);
                  rightUser = new Op(dNum);
                  add = new Add(leftUser, rightUser);
                  prevBase = add;
                  i = i + 3;
              }
              else {
                  cout << "Invalid 4" << endl;
                  return nullptr;
              }
          }         
      
          // 2.check if next is sub
          else if ((*input[i+1] == '-')) {
              num = (*input[i+2]);
              //3. 
              if (isdigit(num)) {
                  dNum = stod(input[i+2]);
                  rightUser = new Op(dNum);
                  sub = new Sub(leftUser, rightUser);
                  prevBase = sub;
                  i = i + 3;
              }
              else {
                  cout << "Invalid 5" << endl;
                  return nullptr;
              }
          }     
            
          else {
              cout << "Invalid 6" << endl;
              return nullptr;
          }
      
      
      }
      
      // 1.check if first is multi
      else if ((*input[i] == '*')) {
          num = (*input[i+1]);
          // 2. check if next is pow
          if ((*input[i+1] == '*')) {
            num = (*input[i+2]);
            //3. check if next + 1 is number
            if (isdigit(num)) {
                dNum = stod(input[i+2]);
                rightUser = new Op(dNum);
                pow = new Pow(prevBase, rightUser);
                prevBase = pow;
                i = i + 3;
            }
            else {
                cout << "Invalid 7" << endl;
                return nullptr;
            }
          num = (*input[i+1]);
          }

          // 2. check if next is number
          //num = (*input[i+1]);
          else if (isdigit(num)) {
              dNum = stod(input[i+1]);
              rightUser = new Op(dNum);
              mult = new Mult(prevBase, rightUser);
              prevBase = mult;
              i = i + 2;
          }
          else {
              cout << "Invalid 8" << endl;
              return nullptr;
          }
     }
     // 1. check if first is division
     else if ((*input[i] == '/')) {
         num = (*input[i+1]);
         // 2. check if next is number
         if (isdigit(num)) {
            dNum = stod(input[i+1]);
            rightUser = new Op(dNum);
            div = new Div(prevBase, rightUser);
            prevBase = div;
            i = i + 2;
         }
         else {
             cout << "Invalid 9" << endl;
             return nullptr;
         }

     }

     // 1. check if first is add
     else if ((*input[i] == '+')) {
         num = (*input[i+1]);
         // 2. check if next is number
         if (isdigit(num)) {
            dNum = stod(input[i+1]);
            rightUser = new Op(dNum);
            add = new Add(prevBase, rightUser);
            prevBase = add;
            i = i + 2;
         }
         else {
             cout << "Invalid 10" << endl;
             return nullptr;
         }

    }

     // 1. check if first is sub
     else if ((*input[i] == '-')) {
         num = (*input[i+1]);
         // 2. check if next is number
         if (isdigit(num)) {
            dNum = stod(input[i+1]);
            rightUser = new Op(dNum);
            sub = new Sub(prevBase, rightUser);
            prevBase = sub;
            i = i + 2;
         }
         else {
             cout << "Invalid 11" << endl;
             return nullptr;
         }

     }
     this->root = prevBase;
  }  
  return this->root;

}

