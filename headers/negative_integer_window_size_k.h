#pragma once 

#include <vector>
#include <queue>

class NegativeIntegerInWindow {
public:
    std::vector<int> getNegativeIntegersInAllWindows(const std::vector<int>& arr, int k);
}; 

std::vector<int> NegativeIntegerInWindow::getNegativeIntegersInAllWindows(const std::vector<int>& arr, int k) {
    std::vector<int> result(arr.size() - k + 1, 0);

    std::deque<int> dq;

    int i{0};
    for(; i < k; ++i) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
    }

    int resIndex{0};
    while(!dq.empty() && i - k >= dq.front()) {
        dq.pop_front();
    }
    if(!dq.empty()) {
        result[resIndex++] = arr[dq.front()];
    }

    for(; i < arr.size(); ++i) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
        while(!dq.empty() && i - k >= dq.front()) {
            dq.pop_front();
        }
        if(!dq.empty()) {
            result[resIndex++] = arr[dq.front()];
        }
        else {
            result[resIndex++] = 0;
        }
    }

    return result;
}