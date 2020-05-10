#include <iostream>
#include <vector>
#include <algorithm>
// 2D Array image rotation
// https://leetcode.com/problems/rotate-image/

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto & row: matrix) {
            std::reverse(row.begin(), row.end());
        }
    }
};

int main() {
    vector<vector<int>> input = {{1,2,3},
                                 {4,5,6},
                                 {7,8,9}};
    vector<vector<int>> expected = {{7,4,1},{8,5,2},{9,6,3}};
    Solution().rotate(input);
    for (int i = 0; i < 3; ++i) {
        assert(input[i] == expected[i]);
    }

    input = {{5, 1, 9,11},
             {2, 4, 8,10},
             {13, 3, 6, 7},
             {15,14,12,16}};
    expected = {{15,13, 2, 5},
  {14, 3, 4, 1},
  {12, 6, 8, 9},
  {16, 7,10,11}};
  Solution().rotate(input);
    for (int i = 0; i < 3; ++i) {
        assert(input[i] == expected[i]);
    }
    return 0;
}