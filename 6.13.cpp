#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0) {
            return;
        }
        k %= N;
        if (k > 0) {
            int d = gcd(N, k);
            for (int start = 0; start < d; ++start) {
                rotateGroup(nums, start, k);
            }
        }
    }
    
    void rotateGroup(vector<int> &nums, int from, int K) {
        int tmp = nums[from];
        int to = (from + K) % nums.size();
        while (to != from) {
            swap(tmp, nums[to]);
            to = (to + K) % nums.size();
        }
        swap(tmp, nums[from]);
    }
    
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
};

int main() {
    vector<int> input = {1,2,3,4,5,6,7};
    vector<int> expected = {5,6,7, 1,2,3, 4};
    Solution().rotate(input, 3);
    assert(input == expected);
    return 0;
}