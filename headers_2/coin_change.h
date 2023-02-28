#pragma once

#include <vector>

class CoinChange {
public:
    int getWaysToMakeChange(int sum, const std::vector<int>& coins);
};

int CoinChange::getWaysToMakeChange(int sum, const std::vector<int>& coins) {
    std::vector<std::vector<int>> dpTable(coins.size() + 1, std::vector<int>(sum + 1, 0));

    for(int i = 1; i <= coins.size(); ++i) {
        dpTable[i][0] = 1;
    }

    for(int i = 1; i <= coins.size(); ++i) {
        for(int j = 1; j <= sum; ++j) {
            int withCoin = (j >= coins[i - 1] ? dpTable[i][j - coins[i - 1]] : 0);
            int withoutCoin = dpTable[i-1][j];
            dpTable[i][j] = withCoin + withoutCoin;
        }
    }

    return dpTable[coins.size()][sum];
}