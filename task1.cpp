// Задача 1: проверка правильной скобочной последовательности
#include <iostream>
#include <string>
#include <stack>

bool isBalanced(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            char open = c == ')' ? '(' : c == ']' ? '[' : '{';
            if (st.empty() || st.top() != open) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << (isBalanced(s) ? "yes" : "no") << '\n';
}
//clang++ -std=c++17 task1.cpp -o task1 && ./task1

