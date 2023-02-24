#pragma once

#include <string>
#include <algorithm>

class NextGreaterNumberWithSameDigits {
public:
    std::string getNextGreater(const std::string& number);
};

std::string NextGreaterNumberWithSameDigits::getNextGreater(const std::string& number) {
    std::string res{number.begin(), number.end()};

    int i = res.size() - 2;
    for(; i >= 0; --i) {
        if(res[i] < res[i+1]) {
            break;
        }
    }

    int smallestOnRight = i + 1;
    for(int j = i + 2; j < res.size(); ++j) {
        if(res[j] > res[i] && res[j] < res[smallestOnRight]) {
            smallestOnRight = j;
        }
    }

    std::swap(res[smallestOnRight], res[i]);

    std::sort(res.begin() + i + 1, res.end());

    return res;
}