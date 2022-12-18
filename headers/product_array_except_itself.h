#pragma once

#include <vector>

class ProductArrayExceptItself {
public:
    std::vector<int> getProdArray(const std::vector<int>& arr);
};

std::vector<int> ProductArrayExceptItself::getProdArray(const std::vector<int>& arr) {
    std::vector<int> prodArr(arr.size(), 1);

    int temp = 1;
    for(int i = 0; i < arr.size(); ++i) {
        prodArr[i] = temp;
        temp *= arr[i];
    }

    temp = 1;
    for(int i = arr.size() - 1; i >= 0; --i) {
        prodArr[i] *= temp;
        temp *= arr[i];
    }

    return prodArr;
}