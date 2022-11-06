#pragma once 

#include <optional>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

class FourElementsWithGivenSum {
public:
    using FourElementsType = std::tuple<int, int, int, int>;
    std::optional<FourElementsType> getElements(const std::vector<int>& arr, int X); 
};

std::optional<FourElementsWithGivenSum::FourElementsType> FourElementsWithGivenSum::getElements(const std::vector<int>& arr, int X) {
    std::unordered_map<int, std::pair<int, int>> mp;
    for(int i = 0; i < arr.size(); ++i) {
        for(int j = i + 1; j < arr.size(); ++j) {
            mp.insert(std::make_pair(arr[i] + arr[j], std::make_pair(i, j)));
        }
    }

    for(int i = 0; i < arr.size(); ++i) {
        for(int j = i + 1; j < arr.size(); ++j) {
            int sum = arr[i] + arr[j];
            if(mp.find(X - sum) != mp.end()) {
                auto elements = mp[X - sum];
                if((elements.first != i && elements.second != j) && (elements.first != j && elements.second != i)) {
                    std::vector<int> elementsArr{arr[i], arr[j], arr[elements.first], arr[elements.second]};
                    std::sort(elementsArr.begin(), elementsArr.end());
                    return std::make_optional(std::make_tuple(elementsArr[0], elementsArr[1], elementsArr[2], elementsArr[3]));
                }
            }
        }
    }
    return std::nullopt;
}