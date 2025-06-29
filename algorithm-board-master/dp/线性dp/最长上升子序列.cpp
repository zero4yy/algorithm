// https://leetcode.cn/problems/longest-increasing-subsequence/description/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int x : nums) {
            int l = 0, r = dp.size();
            while (l < r) {
                int m = l + r >> 1;
                if (dp[m] < x) {    // 求最长非降子序列就改成<=
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (l == (int)dp.size()) {
                dp.push_back(x);
            } else {
                dp[l] = min(dp[l], x);
            }
        }
        return (int)dp.size();
    }
};