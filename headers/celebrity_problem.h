#pragma once

#include <vector>
#include <optional>
#include <stack>

class CelebrityProblem {
public:
    using AcquaintanceMatrix = std::vector<std::vector<int>>;

    std::optional<int> findCelebrity(const AcquaintanceMatrix& matrix);
};

std::optional<int> CelebrityProblem::findCelebrity(const CelebrityProblem::AcquaintanceMatrix& matrix) {
    std::stack<int> s;
    for(int i = 0; i < matrix.size(); ++i) {
        s.push(i);
    }

    while(s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if(matrix[A][B] == 1) {
            // B may be celebrity
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    int candidate = s.top();
    for(int i = 0; i < matrix.size(); ++i) {
        if(i != candidate) {
            if(matrix[i][candidate] == 0 || matrix[candidate][i] == 1) {
                return std::nullopt;
            }
        }
    }
    return candidate;
}