#pragma once

#include <vector>
#include <numeric>

class MergeArrayIntoAnotherArray {
public:
    static const int NA = std::numeric_limits<int>::min();
    void doMerge(std::vector<int>& bigArray, const std::vector<int>& arr);
private:
    void moveNonNAToEnd(std::vector<int>& bigArray);
};

void MergeArrayIntoAnotherArray::moveNonNAToEnd(std::vector<int>& bigArray) {
    int k = bigArray.size() - 1;
    int i = k;

    while(i >= 0) {
        if(bigArray[i] != NA) {
            bigArray[k] = bigArray[i];
            --k;
        }
        --i;
    }
}

void MergeArrayIntoAnotherArray::doMerge(std::vector<int>& bigArray, const std::vector<int>& arr) {
    moveNonNAToEnd(bigArray);

    int i = bigArray.size() - arr.size() - 1;
    int j = 0;
    int k = 0;

    while(i < bigArray.size() && j < arr.size()) {
        if(bigArray[i] < arr[j]) {
            bigArray[k] = bigArray[i];
            ++k;
            ++i;
        }
        else {
            bigArray[k] = arr[j];
            ++j;
            ++k;
        }
    }
    while(i < bigArray.size()) {
        bigArray[k] = bigArray[i];
        ++k;
        ++i;
    }
    while(j < arr.size()) {
        bigArray[k] = arr[j];
        ++j;
        ++k;
    }
}