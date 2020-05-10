#include <string>
#include <cctype>
#include <cassert>
#include <iostream>
using namespace std;

// Simple regular expression matching
// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchImpl(s, p, 0, 0);
    }
    
    bool isMatchImpl(string const& s, string const &pattern, int si, int pi) {
        if (pi >= pattern.size()) {
            return si >= s.size();
        }
        if (si >= s.size()) {
            for (int i = pi; i < pattern.size(); i += 2) {
                if (pattern[i + 1] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (isalpha(pattern[pi]) || pattern[pi] == '.') {
            if (pattern.size() - pi >= 2 && pattern[pi + 1] == '*') {
                bool result = isMatchImpl(s, pattern, si, pi + 2);
                int next = si;
                while (!result && next < s.size() && (pattern[pi] == '.' || s[next] == pattern[pi])) {
                    result = isMatchImpl(s, pattern, next + 1, pi + 2);
                    ++next;
                }
                return result;
            } else {
                return (pattern[pi] == '.' || s[si] == pattern[pi])
                    && isMatchImpl(s, pattern, si + 1, pi + 1);
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    assert(solution.isMatch("", "b*a*"));
    assert(!solution.isMatch("aa", "b*a"));
    assert(!solution.isMatch("aaa", "ab*a"));
    assert(solution.isMatch("helloWorld" ,".*"));
    assert(solution.isMatch("helloWorld" ,"hello.*"));
    assert(solution.isMatch("" ,"a*"));
    assert(solution.isMatch("a" ,"a*"));
    assert(solution.isMatch("aa" ,"a*"));
    assert(solution.isMatch("aaa" ,"a*"));
    assert(!solution.isMatch("aa" ,"a"));
    assert(solution.isMatch("aab" ,"c*a*b"));
    assert(!solution.isMatch("mississippi", "mis*is*p*."));
    assert(solution.isMatch("mississippi", "mis*is*ip*."));
    cout << "OK" << endl;
    return 0;
}