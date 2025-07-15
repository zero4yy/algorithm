#include <bits/stdc++.h>

using namespace std;

/*
01背包变形
背包体积: target
物品: 每一个num
体积: num的值
价值: 都为1
恰好装满
*/

class Solution {
public:
    const int INF = 0x3f3f3f3f; 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -INF);
        dp[0] = 0;
        for(int num : nums) {
            for(int j = target; j >= num; --j) {
                dp[j] = max(dp[j], dp[j - num] + 1);
            }
        }
        return dp[target] > 0 ? dp[target] : -1;
    }
};

int main() {
    vecotr<int> nums = {1, 2, 3, 4, 5};
    int target = 9;
    Solution sl;
    
    return 0;
}