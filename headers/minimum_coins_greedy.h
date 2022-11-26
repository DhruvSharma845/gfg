#pragma once

#include <vector>

class MinimumCoins {
public:
    int findMinimumCoins(int V, const std::vector<int>& coins);
};

int MinimumCoins::findMinimumCoins(int V, const std::vector<int>& coins) {
    auto count = int{0};
    for(int i = coins.size() - 1; i >= 0 && V != 0; --i) {
        if(coins[i] <= V) {
            count += (V / coins[i]);
            V = V % coins[i];
        }
    }
    return count;
}