#pragma once

#include <vector>
#include <algorithm>

class PancakeSorting {
private:
    void flip(std::vector<int>& arr, int start, int end);
public:
    std::vector<int> doSort(const std::vector<int>& arr);
};

std::vector<int> PancakeSorting::doSort(const std::vector<int>& arr) {
    std::vector<int> res(arr.begin(), arr.end());
    for(int i = res.size() - 1; i > 1; --i) {
        auto itr = std::max_element(res.begin(), res.begin() + (i + 1));
        int indexMax = std::distance(res.begin(), itr);

        if(indexMax != i) {
            flip(res, 0, indexMax);
            flip(res, 0, i);
        }
    }
    return res;
}

void PancakeSorting::flip(std::vector<int>& arr, int start, int end) { 
    while (start <= end)  { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        ++start; 
        --end; 
    } 
}