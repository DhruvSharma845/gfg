#pragma once

#include <string>
#include <optional>

class FindPatternsOf101 {
public:
    std::optional<int> findCount(const std::string& str);
};

std::optional<int> FindPatternsOf101::findCount(const std::string& str) {
    int count = 0;
    for(int i = 0; i < str.size();) {
        int j = i + 1;
        if(str[i] == '1') {
            if(j < str.size() && str[j+1] == '0') {
                while(j < str.size() && str[j] == '0') {
                    ++j;
                }
                if(j < str.size() && str[j] == '1') {
                    ++count; 
                }
            }
        }
        i = j;
    }
    return count;
}