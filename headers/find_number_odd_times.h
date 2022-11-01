#pragma once 

#include <vector>

class NumberOccuringOddNumOfTimes {
public:
    int getNumber(const std::vector<int>& arr);
};

int NumberOccuringOddNumOfTimes::getNumber(const std::vector<int>& arr) {
    int x = 0;
    for(const auto& elem: arr) {
        x = x ^ elem;
    }
    return x;
}