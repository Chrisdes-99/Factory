#include "gtest/gtest.h"
#include "test.hpp"
#include "BaseFactory.hpp"
#include "Base.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
