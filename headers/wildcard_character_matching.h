#pragma once

#include <string>

class WildcardPatternMatcher {
public:
    bool doesMatch(const std::string& str, const std::string& pattern);
};

bool WildcardPatternMatcher::doesMatch(const std::string& str, const std::string& pattern) {
    if(str.empty() && pattern.empty()) {
        return true;
    }
    if(pattern.empty() || str.empty()) {
        return false;
    }
    if(pattern[0] == str[0] || pattern[0] == '?') {
        return doesMatch(str.substr(1, str.size() - 1), pattern.substr(1, pattern.size() - 1));
    }
    else if(pattern[0] == '*') {
        bool withCurrentChar = doesMatch(str.substr(1, str.size() - 1), pattern);
        bool withoutCurrentChar = doesMatch(str, pattern.substr(1, pattern.size() - 1));
        return (withCurrentChar || withoutCurrentChar);
    }
    return false;
}