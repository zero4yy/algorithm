#include <bits/stdc++.h>

using namespace std;

/*
target = n;
物品: n1^x,n2^x,n3^x,...
体积，价值: nk^x
求装满的方案数
*/
class Solution {
public:
    const int mod = 1e9+7;
    int qmi(int m, int k) {
        int res = 1, t = m;
        while(k) {
            if(k & 1) res = res * t;
            t = t * t;
            k >>= 1;
        }
        return res;
    }
    int numberOfWays(int n, int x) {
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; qmi(i, x) <= n; i ++) {
            int nx = qmi(i, x);
            for(int j = n; j >= nx; -- j) {
                dp[j] = (dp[j] + dp[j - nx]) % mod; 
            }
        }
        return dp[n];
    }
};

int main() {
    
    return 0;
}