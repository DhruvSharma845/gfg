#pragma once

#include <queue>

class SmallestMultipleMadeOf0And9 {
public:
    int findMultipleOf(int N);
};

int SmallestMultipleMadeOf0And9::findMultipleOf(int N) {
    std::queue<int> q;
    q.push(9);

    int limit = 10000;
    while(--limit > 0) {
        int tp = q.front();
        q.pop();

        if(tp % N == 0) {
            return tp;
        }

        q.push(tp * 10 + 0);
        q.push(tp * 10 + 9);
    }
    return -1;
}