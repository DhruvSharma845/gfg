#pragma once

#include <cstddef>
#include <string>
#include <stack>


class MinBracketReversalsToBalance {
public:
    std::size_t getCount(const std::string& expression);
};

std::size_t MinBracketReversalsToBalance::getCount(const std::string& expression) {
    std::stack<char> st;
    for(auto ch: expression) {
        if(ch == '{') {
            st.push(ch);
        }
        else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
    }
    int m = static_cast<int>(st.size());
    int n = 0;
    while(!st.empty()) {
        if(st.top() == '{') {
            ++n;
        }
        st.pop();
    }
    return ((m/2) + (n%2));
}