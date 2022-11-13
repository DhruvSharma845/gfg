#pragma once

#include <vector>
#include <numeric>

class ArrayRotater {
public:
    void rotate(std::vector<int>& arr, int d);
};

void ArrayRotater::rotate(std::vector<int>& arr, int d) {
    int numBlocks = std::gcd(arr.size(), d);
    for (int i = 0; i < numBlocks; ++i) {
        int temp = arr[i];
        int j = i;
        int k;
        do {
            k = j + d;
            k = k % arr.size();
            if(k == i) {
                break;
            }
            arr[j] = arr[k];
            j = k;
        } while(k != i);
        arr[j] = temp;
    }
    
}