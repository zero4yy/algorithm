#include <bits/stdc++.h>
#include <algorithm>
#include <ranges>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> ans;

        for(int i = 0; i < n - 2; i ++) {
            int x = nums[i];
            if(i && x == nums[i - 1]) continue;
            if(x + nums[i + 1] + nums[i + 2] > 0) break;
            if(x + nums[n - 2] + nums[n - 1] < 0) continue;
            
            int j = i + 1, k = n - 1; 
            while(j < k) {
                int sum = x + nums[j] + nums[k];
                if(sum > 0) k --;
                else if(sum < 0) j ++;
                else {
                    ans.push_back({x, nums[j], nums[k]});
                    
                    //关键部分，之前卡住了
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]) j ++; // 移动到下一个不同的元素
                    while(j < k && nums[k] == nums[k + 1]) k --; // 移动到下一个不同的元素
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = s.threeSum(nums);
    for(auto x : ans) {
        for(auto y : x)
            cout << y << ',';
        cout << endl;
    }
}