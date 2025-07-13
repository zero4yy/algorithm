#include <bits/stdc++.h>
using namespace std;

// 哈希 + 前缀和
/*
其核心思想是，任意子数组（从i到j）的和都可以表示为两个前缀和的差 (prefix[j] - prefix[i-1])。
因此，问题就从 “寻找和为k的子数组” 转化为 “寻找满足 prefix[j] - prefix[i-1] = k 的下标对”。

我们通过一次遍历，边计算当前的前缀和，边用哈希表快速查找历史上是否存在过值为 当前前缀和 - k 的前缀和，
并累加其出现次数，从而在线性时间内高效地完成统计。
*/

/*2次遍历*/
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> s(n + 1);
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i ++) 
            s[i + 1] = s[i] + nums[i];
        
        // s[j] - s[i] = k -> s[i] = s[j] - k
        // 寻找 s[j] 左边 (s[i] == s[j] - k) 的情况
        for(int x : s) {
            ans += cnt.contains(x - k) ? cnt[x - k] : 0; 
            cnt[x] ++;
        }
        return ans;
    }
};

/*1次遍历*/
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        // 哈希表 存储{前缀和 -> 出现次数}
        unordered_map<int, int> preSumCnt;
        // 初始化 前缀和为0出现过1次
        preSumCnt[0] = 1;
        int preSum = 0; // 记录前缀和
        

        for(int num : nums) {
            // 1. 计算当前的前缀和
            preSum += num;

            // 2. 寻找目标前缀和 `currentSum - k` 是否在哈希表中
            if(preSumCnt.count(preSum - k)) 
                ans += preSumCnt[preSum - k];
            
            // 3. 将当前的前缀和存入哈希表（或增加其计数）
            preSumCnt[preSum] ++;
        }

        return ans;
    }
};
int main() {
    vector<int> nums = {-1,-1,1};
    int k = 0;
    Solution1 s;
    cout << s.subarraySum(nums, k);
    return 0;
}