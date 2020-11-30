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

  for(int i= 0; i < length;i++){
          
      // 1.check if first is digit
      if (isdigit(input[i])) {
          leftUser == new Op(input[i]);

          // 2.check if next is multi
          if (input[i+1] == "*") {

              // 3.check if next + 1 is pow
              if (input[i+2] == "*") {
                
                // 4.check if next + 2 is number
                if (isdigit(input[i+3])) {
                    rightUser = input[i+3];
                    pow = new Pow(leftUser, rightUser);
                    prevBase = pow;
                }
                else {
                    cout << "Invalid" << endl;
                }
              }

              // 3.check if next + 1 is number
              else if (isdigit(input[i+2])) {
                rightUser = new Op(input[i+2]);
                multi = new Mult(leftUser, rightUser);
                prevBase = multi;
              }
              else {
                  cout << "Invalid" << endl;
              }

          // 2.check if next is division
          else if (input[i+1] == "/") {
              // 3.
              if (isdigit(input[i+2]) {
                  rightUser = new Op(input[i+2];
                  div = new Div(leftUser, rightUser);
                  prevBase = div;
              }
              else {
                  cout << "Invalid" << endl;
              }
          }

          // 2.check if next is add
          else if (input[i+1] == "+") {
              //3. 
              if (isdigit(input[i+2]) {
                  rightUser = new Op(input[i+2];
                  add = new Add(leftUser, rightUser);
                  prevBase = add;
              }
              else {
                  cout << "Invalid" << endl;
              }
          }         
      
          // 2.check if next is sub
          else if (input[i+1] == "-") {
              //3. 
              if (isdigit(input[i+2]) {
                  rightUser = new Op(input[i+2];
                  sub = new Sub(leftUser, rightUser);
                  prevBase = sub;
              }
              else {
                  cout << "Invalid" << endl;
              }
          }     
            
          else {
              cout << "Invalid" << endl;
          }
      
      
      
      // 1.check if first is multi
      else if (input[i] == "*") {

          // 2. check if next is pow
          if (input[i+1] == "*") {
            
            //3. check if next + 1 is number
            if (isdigit(input[i+2])) {
                rightUser = new Op(input[i+2]);
                pow = new Pow(prevBase, rightUser);
                prevBase = pow;
            }
            else {
                cout << "Invalid" << endl;
            }
          }

          // 2. check if next is number
          else if (isdigit(input[i+1])) {
              rightUser = new Op(input[i+1]);
              mult = new Mult(prevBase, rightUser);
              prevBase = mult;
          }
          else {
              cout << "Invalid" << endl;
          }

     // 1. check if first is division
     else if (input[i] == "/") {

         // 2. check if next is number
         if (isdigit(input[i+1]) {
            rightUser = new Op(input[i+1]);
            div = new Div(prevBase, rightUser);
            prevBase = div;
         }
         else {
             cout << "Invalid" << endl;
         }

     }

     // 1. check if first is add
     else if (input[i] == "+") {

         // 2. check if next is number
         if (isdigit(input[i+1]) {
            rightUser = new Op(input[i+1]);
            add = new Add(prevBase, rightUser);
            prevBase = add;
         }
         else {
             cout << "Invalid" << endl;
         }

    }

     // 1. check if first is sub
     else if (input[i] == "-") {

         // 2. check if next is number
         if (isdigit(input[i+1]) {
            rightUser = new Op(input[i+1]);
            sub = new Sub(prevBase, rightUser);
            prevBase = sub;
         }
         else {
             cout << "Invalid" << endl;
         }

       }

  return this->root;
}

