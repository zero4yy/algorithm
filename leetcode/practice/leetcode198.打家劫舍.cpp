#include <iostream>
#include <vector>
using namespace  std;

/*
1.状态表示:  f[i][bool] 前i个物品, 是否选择第i个物品

2.状态计算: 
            f[i][0] = max(f[i - 1][0], f[i - 1][1])
            f[i][1] = f[i - 1][0] + a[i];
*/
class Solution1 {
public:
    int f[105][2];
    int rob(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i <= n; i ++) {
            f[i][0] = max(f[i - 1][0], f[i-1][1]);
            f[i][1] = f[i - 1][0] + nums[i - 1];
        }
    return max(f[n][0], f[n][1]);
    }
};

/*
优化
1.状态表示:  f[i] 前 i 个物品, 能取得的最大价值

2.状态计算:  第 i 个不选, f[i - 1], 第 i 个选, f[i - 2] + a[i]
            f[i] = max(f[i - 1],f[i - 2] + a[i])
*/
class Solution2 {
public:
    int f[105];
    int rob(vector<int>& nums) {
        int n = nums.size();
        f[1] = nums[1];
        for(int i = 2; i <= n; i ++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
        }
    return f[n];
    }
};


int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution2 sl;
    cout << sl.rob(nums);
    return 0;
}