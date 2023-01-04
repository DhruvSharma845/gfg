#pragma once

#include <queue>

class HalvesInterleaving {
public:
    void doInterleaving(std::queue<int>& q);
};

void HalvesInterleaving::doInterleaving(std::queue<int>& q) {
    std::queue<int> tempQ;
    int sz = q.size();
    for(int i = 0; i < sz / 2; ++i) {
        tempQ.push(q.front());
        q.pop();
    }
    
    for(int i = 0; i < sz / 2; ++i) {
        q.push(tempQ.front());
        q.push(q.front());
        tempQ.pop();
        q.pop();
    }
}