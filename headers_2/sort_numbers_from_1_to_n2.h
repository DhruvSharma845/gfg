#pragma once

#include <vector>

class NumberSorterFrom0ToN2 {
private:
    void doCountSort(std::vector<int>& arr, int base);
public:
    std::vector<int> doSort(const std::vector<int>& arr);
};

void NumberSorterFrom0ToN2::doCountSort(std::vector<int>& arr, int base) {
    std::vector<int> count(arr.size(), 0);
    int N = static_cast<int>(arr.size());
    for(int i = 0; i < arr.size(); ++i) {
        count[(arr[i] / base) % N]++; 
    }

    for(int i = 1; i < N; ++i) {
        count[i] += count[i-1];
    }
    std::vector<int> output(N, 0);
    for(int i = N - 1; i >=0; --i) {
        output[count[(arr[i] / base) % N] - 1] = arr[i]; 
        count[(arr[i] / base) % N]--;
    }

    arr.assign(output.begin(), output.end());
}

std::vector<int> NumberSorterFrom0ToN2::doSort(const std::vector<int>& arr) {
    std::vector<int> clonedArr(arr.begin(), arr.end());
    doCountSort(clonedArr, 1);
    doCountSort(clonedArr, arr.size());
    return clonedArr;
}