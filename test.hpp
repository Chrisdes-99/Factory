#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <iostream>
#include "gtest/gtest.h"

#include "BaseFactory.hpp"

#include "./Lab-04-Composite/add.hpp"
#include "./Lab-04-Composite/pow.hpp"
#include "./Lab-04-Composite/sub.hpp"
#include "./Lab-04-Composite/op.hpp"
#include "./Lab-04-Composite/rand.hpp"
#include "./Lab-04-Composite/mult.hpp"
#include "./Lab-04-Composite/div.hpp"



//parse function will be implemeted in tests

TEST(MultTest, MultEvaluationNonZero) {
    Op* a = new Op(4.321);
    Op* b = new Op(2.231);

    Mult* test = new Mult(a,b);



TEST(DivTest, DivEvaluationNonZero) {
    Op* a = new Op(6.321);
    Op* b = new Op(2.345);

    Div* test = new Div(a,b);



TEST(AddTest, AddEvaluateNonZero) {
    Op* a = new Op(2.466);
    Op* b = new Op(3.98722);
    
    Add* test = new Add(a,b);



TEST(PowTest, PowEvaluateNonZero) {
    Op* a = new Op(2.14);
    Op* b = new Op(3.5222);
    Pow* test = new Pow(a, b);



TEST(SubTest, SubEvaluateNonZero) {
    Op* a = new Op(4.323);
    Op* b = new Op(2.4433);
    Sub* test = new Sub(a, b);


#endif //__TEST_HPP__
