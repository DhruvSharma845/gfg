#pragma once

#include <string>
#include <queue>
#include <unordered_map>
#include <utility>

class RearrangeCharactersDDistanceAway {
public:
    std::string doRearrange(const std::string& input, int D);
};

std::string RearrangeCharactersDDistanceAway::doRearrange(const std::string& input, int D) {
    std::string result(input.size(), ' ');
    int currentIndex = 0;

    std::unordered_map<char, int> frequencyMap;
    for(char c: input) {
        frequencyMap[c]++;
    }
    using PQPair = std::pair<char, int>;
    auto priorityQueueComparator = [](const PQPair& a, const PQPair& b) {
        return a.second < b.second;
    };
    std::priority_queue<PQPair, std::vector<PQPair>, decltype(priorityQueueComparator)> pq(priorityQueueComparator);
    for(const auto& pr: frequencyMap) {
        pq.push(std::make_pair(pr.first, pr.second));
    }

    while(currentIndex < input.size() && !pq.empty()) {
        auto pr = pq.top();
        pq.pop();

        while(currentIndex < result.size() && result[currentIndex] != ' ') {
            ++currentIndex;
        }
        // Unrearrangable case
        if(currentIndex == result.size()) {
            return "";
        }

        for(int i = currentIndex; i < result.size() && pr.second > 0; i += D) {
            result[i] = pr.first;
            pr.second--;
        }
        // Unrearrangable case
        if(pr.second > 0) {
            return "";
        }
    }
    return result;
}