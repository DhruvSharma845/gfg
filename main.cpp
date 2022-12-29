#include <iostream>
#include <gtest/gtest.h>

int main(int, char**) {
    std::cout << "Running google tests!!!";
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
