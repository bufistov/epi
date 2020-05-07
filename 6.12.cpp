#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int index = nums.size() - 2;
    while (index >= 0 && nums[index] >= nums[index+1]) {
        --index;
    }
    if (index < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        ++index;
        reverse(nums.begin() + index, nums.end());
        auto ub = upper_bound(nums.begin() + index, nums.end(), nums[index - 1]);
        swap(nums[index - 1], nums[ub - nums.begin()]);
    }
}

int main() {
    vector<int> test = {1, 2, 1};
    vector<int> expected = {2, 1, 1};
    nextPermutation(test);
    assert(test == expected);
    return 0;
}