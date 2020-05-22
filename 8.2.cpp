#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    typedef long long ll_t;
    int evalRPN(vector<string>& tokens) {
        stack<ll_t> operands;
        for (auto token: tokens) {
            ll_t op1, op2;
            if (isOperator(token)) {
                ll_t op1 = operands.top(); operands.pop();
                ll_t op2 = operands.top(); operands.pop();
                switch (token[0]) {
                    case '*':
                        operands.push(op1 * op2);
                        break;
                    case '/':
                        operands.push(op2 / op1);
                        break;
                    case '+':
                        operands.push(op1 + op2);
                        break;
                    case '-':
                        operands.push(op2 - op1);
                        break;

                }
            } else {
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }
    
    bool isOperator(string const& token) {
        return token.size() == 1 && (token[0] == '*' || token[0] == '/' || token[0] == '+'
                                     || token[0] == '-');
    }
};

int main() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    assert(Solution().evalRPN(tokens) == 22);
    return 0;
}