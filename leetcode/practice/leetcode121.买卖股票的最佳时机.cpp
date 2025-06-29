#include <bits/stdc++.h>

using namespace std;

// 类似接雨水 维护前缀最小值 
// [7,1,5,3,6,4]
// 从左向右扫，维护最小值 [7,1,1,1,1,1]
// 从右向左扫，维护最大值 [7,6,6,6,6,4]
// 求差
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> in(n, 0), out(n, 0);
        in[0] = prices[0];
        for(int i = 1; i < n; i ++) {
            in[i] = min(in[i - 1], prices[i]);
        }

        out[n - 1] = prices[n - 1];
        for(int i = n - 1; i >= 1; i --) {
            out[i - 1] = max(out[i], prices[i - 1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, out[i] - in[i]);
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minPrice = prices[0];
        for(int cur : prices) {
            minPrice = min(minPrice, cur);
            ans = max(ans, cur - minPrice);
        }
        return ans;
    }
};


int main() {

    return 0;
}