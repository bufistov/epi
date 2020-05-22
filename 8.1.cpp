#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

// Leetcode charges for this problem:
// https://leetcode.com/problems/max-stack
struct StackWithMax {
    stack<int> nonDominated;
    stack<int> elements;

    void push(int x) {
        elements.push(x);
        if (nonDominated.empty() || x >= nonDominated.top()) {
            nonDominated.push(x);
        }
    }

    int max() const {
        return nonDominated.top();
    }

    int top() const {
        return elements.top();
    }

    int pop() {
        int x = elements.top();
        elements.pop();
        if (x == nonDominated.top()) {
            nonDominated.pop();
        }
        return x;
    }

    int size() const {
        return elements.size();
    }
};

int main() {
    StackWithMax stack;
    stack.push(2);
    assert(stack.size() == 1);
    assert(stack.max() == 2);
    
    stack.push(5);
    assert(stack.size() == 2);
    assert(stack.max() == 5);

    stack.push(3);
    assert(stack.max() == 5);

    stack.pop(); stack.pop();
    assert(stack.max() == 2);
    assert(stack.size() == 1);
    for (int j = 10; j >= 0; --j) {
        stack.push(j);
    }
    assert(stack.max() == 10);
    for (int i = 0; i <= 9; ++i) {
        stack.pop();
    }
    assert(stack.max() == 10);
    stack.pop();
    assert(stack.max() == 2);
    assert(stack.size() == 1);
    return 0;
}