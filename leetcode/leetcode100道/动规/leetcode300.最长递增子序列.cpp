#include <iostream>
#include <vector>

using namespace std;
// dp[i] 表示以 num[i] 结尾的最长递增序列
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < i; j ++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if(ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};

int main() {

    return 0;
}