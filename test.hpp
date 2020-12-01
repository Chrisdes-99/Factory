#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <iostream>
#include "gtest/gtest.h"

#include "BaseFactory.cpp"
#include "Base.hpp"

TEST(Parse,Mult)
{
  char* test[4]; test[0]= "calculator"; test[1] = "3"; test[2] = "*"; test[3] = "6";

  Base* tree = BaseFactory().parse(test,4);

  EXPECT_EQ(tree->stringify(), "3.000000 * 6.000000");
  EXPECT_EQ(tree->evaluate(),18);
}



TEST(Parse,Divide)
{
  char* test[4]; test[0]= "./calculator"; test[1] = "10"; test[2] = "/"; test[3] = "5";

  Base* tree = BaseFactory().parse(test,4);

  EXPECT_EQ(tree->stringify(), "10.000000 / 5.000000");
  EXPECT_EQ(tree->evaluate(),2);
}



TEST(Parse,Add)
{
  char* test[4]; test[0]= "./calculator"; test[1] = "45"; test[2] = "+"; test[3] = "23";

  Base* tree = BaseFactory().parse(test,4);

  EXPECT_EQ(tree->stringify(), "45.000000 + 23.000000");
  EXPECT_EQ(tree->evaluate(),68);
}



TEST(Parse,Sub)
{
  char* test[4]; test[0]= "./calculator"; test[1] = "20"; test[2] = "-"; test[3] = "12";

  Base* tree = BaseFactory().parse(test,4);

  EXPECT_EQ(tree->stringify(), "20.000000 - 12.000000");
  EXPECT_EQ(tree->evaluate(),8);
}



TEST(Parse,Pow)
{
  char* test[5]; test[0]= "./calculator"; test[1] = "2.14";test[2] = "\*";test[3] = "\*"; test[4] = "3.5222";

  Base* tree = BaseFactory().parse(test,5);

  EXPECT_EQ(tree->stringify(), "2.140000 ** 3.522200");
  EXPECT_NEAR(tree->evaluate(),14.58086847543, 0.000001);
}



TEST(Parse,Combo)
{
  char* test[8]; test[0]= "./calculator"; test[1] = "11"; test[2] = "-"; test[3] = "4"; test[4] = "+";test[5] = "7";test[6] = "*"; test[7] = "9";

  Base* tree = BaseFactory().parse(test,8);

  EXPECT_EQ(tree->stringify(), "14.000000 * 9.000000");
  EXPECT_EQ(tree->evaluate(),126);
}



TEST(Parse,ComboPow)
{
  char* test[9]; test[0]= "./calculato"; test[1] = "8"; test[2] = "*";test[3] = "*"; test[4] = "2"; test[5] = "+"; test[6] = "1";test[7] = "*"; test[8] = "10";

  Base* tree = BaseFactory().parse(test,9);

  EXPECT_EQ(tree->stringify(), "65.000000 * 10.000000");
  EXPECT_EQ(tree->evaluate(),650);
}



TEST(Parse,Combo2)
{
  char* test[8]; test[0]= "./calculator"; test[1] = "10"; test[2] = "+"; test[3] = "7";test[4] = "*";test[5] = "15"; test[6] = "-"; test[7] = "15"; 

  Base* tree = BaseFactory().parse(test,8);

  EXPECT_EQ(tree->stringify(), "255.000000 - 15.000000");
  EXPECT_EQ(tree->evaluate(),240);
}



TEST(Parse,ComboNeg)
{
  char* test[6]; test[0]= "./calculator"; test[1] = "10"; test[2] = "+"; test[3] = "7"; test[4] = "-";test[5] = "30"; 

  Base* tree = BaseFactory().parse(test,6);

  EXPECT_EQ(tree->stringify(), "17.000000 - 30.000000");
  EXPECT_NEAR(tree->evaluate(),-13,0.00001);
}



#endif //__TEST_HPP__
