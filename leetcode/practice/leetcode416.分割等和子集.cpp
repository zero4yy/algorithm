#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
背包问题
背包容量: sum/2
物品: 每一个num 体积: num的值 价值: num的值
问: 能否恰好装满背包
初始化: dp[0] = true, dp[else] = false
转移方程: dp[j] = dp[j] || dp[j - num]
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = reduce(nums.begin(), nums.end());
        if(s % 2) return false;

        int m = s / 2;
        vector<bool> f(m + 1, false);
        f[0] = true;
        for(int num : nums) {
            for(int j = m; j >= num; j --) {
                f[j] = f[j - num] || f[j]; // 不选num 和 选num
            }
        }
        return f[m];
    }
};

int main() {
    vecotr<int> nums = {1, 5, 11, 5};
    Solution sl;
    bool ans = sl.canPartition(nums);
    if(ans) cout << "yes\n";
    else cout << "no\n";
    return 0;
}