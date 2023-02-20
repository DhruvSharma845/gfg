#pragma once

#include <vector>
#include <algorithm>

class MinimumSumFromDigitsOfArray {
public:
    int getMinSum(const std::vector<int>& arr);
};

int MinimumSumFromDigitsOfArray::getMinSum(const std::vector<int>& arr) {
    int num1 = 0;
    int num2 = 0;

    std::vector<int> clonedArr{arr.begin(), arr.end()};
    std::sort(clonedArr.begin(), clonedArr.end());

    for(int i = 0; i < clonedArr.size(); ++i) {
        if(i % 2 == 0) {
            num1 = num1 * 10 + clonedArr[i];
        }
        else {
            num2 = num2 * 10 + clonedArr[i];
        }
    }

    return (num1 + num2);
}