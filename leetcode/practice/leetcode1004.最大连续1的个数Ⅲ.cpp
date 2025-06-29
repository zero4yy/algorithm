#include <bits/stdc++.h>

using namespace std;
/*
思路：
滑动窗口 移动右端口
统计当前窗口内 0 的个数 cnt
if cnt > k 收缩win的左端
每次滑动窗口 更新答案
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        if(k >= len) return len;

        int left = 0, zero_cnt = 0, ans = 0;

        for(int right = 0; right < len; right ++) {
            if(nums[right] == 0) zero_cnt ++;
            while(zero_cnt > k) {
                if(nums[left] == 0) zero_cnt --;
                left ++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution sol;
    cout << sol.longestOnes(nums, k);
    return 0;
}