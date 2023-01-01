#pragma once

#include <vector>
#include <algorithm>

class FindDuplicatesIn1ToN {
public:
    std::vector<int> findDuplicates(std::vector<int>& arr);
};

std::vector<int> FindDuplicatesIn1ToN::findDuplicates(std::vector<int>& arr) {
    std::vector<int> res;
    for(int i = 0; i < arr.size(); ++i) {
        int position = arr[i] % arr.size();
        arr[position] = arr[position] + arr.size();
        if(arr[position] >= (2 * arr.size())) {
            res.push_back(position);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}