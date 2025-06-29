#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1), bpre(n + 1);
        pre[0] = 1, bpre[0] = 1;
        vector<int> ans(n);
        for(int i = 1; i <= n; i ++) {
            pre[i] = pre[i - 1] * nums[i - 1];
            bpre[i] = bpre[i - 1] * nums[n - i];
        }

        for(int i = 0; i < n; i ++) ans[i] = pre[i] * bpre[n - i - 1];
        return ans;
    }
};

int main() {

    return 0;
}