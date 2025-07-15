#include <bits/stdc++.h>
/*
给定数列, 划分为两个数组, 使其和最接近
背包问题
*/
using namespace std;

const int N = 1010;

int n, sum = 0, s;
int nums[N];
int dp[N];

void work() {
    s = sum / 2;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i ++) {
        for(int j = s; j >= nums[i]; j --) 
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)  {
        cin >> nums[i];
        sum += nums[i];
    }
    work();
    cout << "two sum value: " << dp[s] << ' ' << (sum - dp[s]) << endl;
    cout << "sub value: " << (sum - dp[s]) - dp[s] << endl;
    return 0;
}
/*
6
1 3 5 8 7 3
*/