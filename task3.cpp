// Задача 3: стек с получением минимума за O(1)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>

class MinStack {
    // Каждый элемент хранит своё значение и минимум на момент добавления
    std::vector<std::pair<int, int>> data;
public:
    void push(int x) {
        int m = data.empty() ? x : std::min(x, data.back().second);
        data.push_back({x, m});
    }
    int pop() {
        if (data.empty()) throw std::out_of_range("pop from empty stack");
        int x = data.back().first;
        data.pop_back();
        return x;
    }
    int top() const {
        if (data.empty()) throw std::out_of_range("top of empty stack");
        return data.back().first;
    }
    int getMin() const {
        if (data.empty()) throw std::out_of_range("min of empty stack");
        return data.back().second;
    }
    bool empty() const { return data.empty(); }
};

int main() {
    MinStack s;
    assert(s.empty());
    s.push(5); s.push(3); s.push(7); s.push(1); s.push(4);
    assert(s.getMin() == 1);
    assert(s.pop() == 4); assert(s.getMin() == 1);
    assert(s.pop() == 1); assert(s.getMin() == 3);
    assert(s.pop() == 7); assert(s.getMin() == 3);
    assert(s.pop() == 3); assert(s.getMin() == 5);
    assert(s.pop() == 5);
    assert(s.empty());

    // Демонстрация
    for (int x : {8, 2, 6, 1, 9}) {
        s.push(x);
        std::cout << "push " << x << " -> min = " << s.getMin() << '\n';
    }
    while (!s.empty()) {
        std::cout << "min = " << s.getMin() << ", pop " << s.pop() << '\n';
    }
}

//clang++ -std=c++17 task3.cpp -o task3 && ./task3
