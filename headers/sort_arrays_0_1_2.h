#pragma once 

#include <vector>

class ArraySorter012 {
public:
    void doSort(std::vector<int>& arr);
};

void ArraySorter012::doSort(std::vector<int>& arr) {
    auto first = int{0};
    auto last = static_cast<int>(arr.size() - 1);

    auto current = int{0};

    for(; current < arr.size(); ++current) {
        if(arr[current]  == 0 && first <= current) {
            std::swap(arr[current], arr[first]);
            ++first;
        }
        else if(arr[current] == 2 && last >= current) {
            std::swap(arr[current], arr[last]);
            --last;
            --current;
        } 
    } 
}