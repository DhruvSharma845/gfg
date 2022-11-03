#pragma once

#include <vector>
#include <stack>

class NextGreaterElement {
public:
    std::vector<int> getNextGreaterElements(const std::vector<int>& arr);
};

std::vector<int> NextGreaterElement::getNextGreaterElements(const std::vector<int>& arr) {
    std::vector<int> result(arr.size(), -1);

    std::stack<int> st;
    for (auto i{0}; i < arr.size(); ++i) {
        
        while(!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()) {
        result[st.top()] = -1;
        st.pop();
    }
    return result;
}