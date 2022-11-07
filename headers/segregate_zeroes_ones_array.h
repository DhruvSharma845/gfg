#pragma once

#include <vector>

class SegregateZeroesAndOnes {
public:
    void doSegregate(std::vector<int>& arr);
};

void SegregateZeroesAndOnes::doSegregate(std::vector<int>& arr) {
    int low = 0; 
    int current = 0;

    while(current < arr.size()) {
        if(arr[current] == 0) {
            std::swap(arr[low], arr[current]);
            ++low;
        }
        ++current;
    }
}