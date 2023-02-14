#pragma once

#include <string>
#include <stack>

class InfixToPostfixConverter {
private:
    int getPrecendence(char op);
public:
    std::string getPostfix(const std::string& infix);
};

int InfixToPostfixConverter::getPrecendence(char op) {
    switch(op) {
        case '^':
            return 3;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            return 0;
    }
    return -1;
}

std::string InfixToPostfixConverter::getPostfix(const std::string& infix) {
    std::stack<char> st;

    std::string output{""};

    for(const auto& ch: infix) {
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            output.push_back(ch);
        }
        else if(ch == '(') {
            st.push(ch);
        }
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                output.push_back(st.top());
                st.pop();
            }
            if(!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
        else {
            while(!st.empty() && getPrecendence(ch) <= getPrecendence(st.top())) {
                output.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        output.push_back(st.top());
        st.pop();
    }

    return output;
}