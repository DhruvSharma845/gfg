#include <iostream>
#include <gtest/gtest.h>

#include "tests.h"
#include "tests_2.h"

int main(int, char**) {
    std::cout << "Running google tests!!!";
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
