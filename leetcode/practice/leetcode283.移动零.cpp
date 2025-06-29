#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 0;
        for(; i < len; i ++) {
            if(nums[i] != 0) nums[j ++] = nums[i];
        }
        for(; j < len; j ++) {
            nums[j] = 0;
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    for(int x : nums) cout << x << ' ';
}