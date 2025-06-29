#include <bits/stdc++.h>
using namespace std;

// 前缀和：起点到某个点的运算结果，重点道某个点的运算结果-----
// MAX[i] = max(MAX[i-1], h[i])
// O(n)复杂度;
class Solution1 {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int n = height.size();
        vector<int> left(n), right(n);

        left[0] = height[0], right[n - 1] = height[n - 1];

        // 从左到右记录最大值，从右到左记录最大值
        for(int i = 1; i < n; i ++) left[i] = max(left[i - 1], height[i]);
        for(int i = n - 2; i >= 0; i --) right[i] = max(right[i + 1], height[i]);

        // 或这样：STL的 partial_sum
        // partial_sum(height.begin(), height.end(), left.begin(), ranges::max);
        // partial_sum(height.rbegin(), height.rend(), right.begin(), ranges::max);


        // for(int x : left) cout << x << ' ';
        // cout << endl;
        // for(int x : right) cout << x << ' ';
        // cout << endl;

        for(int i = 0; i < n; i ++) {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};


int main() {
    Solution1 s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(height);

    return 0;
}