#include <bits/stdc++.h>
using namespace std;

// 哈希 + 前缀和
class Solution {
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
int main() {
    vector<int> nums = {-1,-1,1};
    int k = 0;
    Solution s;
    cout << s.subarraySum(nums, k);
    return 0;
}