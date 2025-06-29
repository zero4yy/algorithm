#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans(n - k + 1);

        for(int i = 0; i < k; i ++) {
            while(dq.size() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans[0] = dq.front();

        for(int i = k; i < n; i ++) {
            if(dq.front() == nums[i - k]) dq.pop_front();
            
            while(dq.size() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);  

            ans[i - k + 1] =dq.front();
        }

        return ans;
    }
};
int main() {
    vector<int> nums = {-1,-1,1};
    int k = 0;
    Solution s;
    return 0;
}