#include <iostream>
#include <vector>
#include <cassert>
// Leetcode
// https://leetcode.com/problems/spiral-matrix/

using std::vector;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        vector<int> result;
        if (height > 0) {
            int width = matrix.front().size();
            int row = 0, column = 0;
            while (height > 0 && width > 0) {
                printCycle(row, column, width, height, matrix, result);
                ++row, ++column;
                width -= 2;
                height -= 2;
            }
        }
        return result;
    }

    void printCycle(int r, int c, int width, int height, vector<vector<int>> const& matrix, vector<int> &result) {
        for (int i = c; i < c + width; ++i) {
            result.push_back(matrix[r][i]);
        }
        for (int j = r + 1; j < r + height; ++j) {
            result.push_back(matrix[j][c + width - 1]);
        }
        if (height > 1) {
            for (int i = c + width - 2; i >= c; --i) {
                result.push_back(matrix[r + height - 1][i]);
            }
        }
        if (width > 1) {
            for (int j = r + height - 2; j > r; --j) {
                result.push_back(matrix[j][c]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> spiral = Solution().spiralOrder(matrix);
    vector<int> expected = {1,2,3,6,9,8,7,4,5};
    assert(spiral == expected);

    matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    expected = {1,2,3,4,8,12,11,10,9,5,6,7};
    assert(Solution().spiralOrder(matrix) == expected);
    return 0;
}