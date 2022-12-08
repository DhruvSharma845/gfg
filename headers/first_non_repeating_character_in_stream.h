#pragma once

#include <unordered_map>
#include <queue>

class FirstNonRepeatingChar {
public:
    std::optional<char> getFirstNonRepeatingChar(char c);
private:
    std::unordered_map<char, int> freqMap;
    std::queue<char> q;
};

std::optional<char> FirstNonRepeatingChar::getFirstNonRepeatingChar(char c) {
    freqMap[c]++;
    if(freqMap[c] == 1) {
        q.push(c);
    }  
    while(!q.empty()) {
        auto elem = q.front();
        if(freqMap[elem] > 1) {
            q.pop();
        }
        else if(freqMap[elem] == 1) {
            return elem;
        }
    }
    return std::nullopt;
}