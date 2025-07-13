/*
这道题是典型的“最小化最大值”问题，其最优解法是**“二分答案”**。

我们将问题从“直接求解一个最优值”转化为一个更容易的判断题：“能否将数组分割成m个子数组，并保证每个子数组的和都不超过给定的上限x？” 
我们对这个上限x在其可能存在的范围（即[数组最大元素, 数组总和]）内进行二分搜索。
对于每一个猜测的x，我们通过贪心策略来验证最少需要多少个子数组才能满足条件。
如果所需数量小于等于m，说明x可能偏大，我们尝试收缩右边界寻找更小的答案；反之，则说明x太小，需要扩大左边界。
最终，二分搜索收敛到的那个满足条件的最小x值，就是我们要求的答案。
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 贪心 check
    bool check(vector<int>& nums, int mid, int k) {
        int need = 1, cur = 0;
        for(int num : nums) {
            if(cur + num > mid) {
                // 当前子数组已满, 开启一个新数组
                cur = 0;
                need ++;
            }
            cur += num;
        }
        // 如果需要的子数组数量小于等于k，说明 限制(mid) 是可行的
        return need <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
        while(left < right) {
            int mid = (right - left) / 2 + left;
            //检查mid是否可行
            if(check(nums, mid, k)) right = mid; // group <= k, mid可行，尝试更小的上限

            else left = mid + 1; // group > k, 分组个数大于k, mid不可行，必须增大上限, 扩大left
        }

        return left;
    }
};

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 3;

    Solution sl;
    cout << sl.splitArray(nums, k);
    return 0;
}