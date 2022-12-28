#pragma once

#include <optional>
#include <tuple>
#include <vector>
#include <algorithm>

class TripletWithSumK {
public:
    std::optional<std::tuple<int, int, int>> getTriplet(const std::vector<int>& arr, int K);
};

std::optional<std::tuple<int, int, int>> TripletWithSumK::getTriplet(const std::vector<int>& arr, int K) {
    std::vector<int> clonedArr(arr.begin(), arr.end());
    std::sort(clonedArr.begin(), clonedArr.end());

    for(int i = 0; i < clonedArr.size() - 1; ++i) {
        int low = i + 1;
        int high = clonedArr.size() - 1;
        while(low < high) {
            int currentSum = clonedArr[i] + clonedArr[low] + clonedArr[high];
            if(currentSum == K) {
                return std::make_tuple(clonedArr[i], clonedArr[low], clonedArr[high]);
            }
            else if(currentSum < K) {
                ++low;
            }
            else {
                --high;
            }
        }
    }
    return std::nullopt;
}