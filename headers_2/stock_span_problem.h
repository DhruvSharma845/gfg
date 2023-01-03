#pragma once

#include <vector>
#include <stack>

class StockSpan {
public:
    std::vector<int> findCountOfLowPriceDays(const std::vector<int>& prices);
};

std::vector<int> StockSpan::findCountOfLowPriceDays(const std::vector<int>& prices) {
    std::vector<int> res(prices.size(), 0);
    int resIndex = 0;
    std::stack<int> st;

    for(int i = 0; i < prices.size(); ++i) {
        while(st.empty() == false && prices[i] >= prices[st.top()]) {
            st.pop();
        }
        res[resIndex] = (st.empty() == true) ? i + 1 : i - st.top();
        ++resIndex;
        if(st.empty() || prices[i] < prices[st.top()]) {
            st.push(i);
        }
    }
    return res;
}