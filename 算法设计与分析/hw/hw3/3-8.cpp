#include <bits/stdc++.h>
using namespace std;
int main() {  
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout); 
    int n, m;  
    cin >> n >> m;  
    vector<int> a(n + 1, 0);  
    vector<int> prefix_sum(n + 1, 0);  
    vector<vector<int>> dp(2, vector<int>(n + 1, INT_MAX)); // 滚动数组  
  
    for (int i = 1; i <= n; ++i) {  
        cin >> a[i];  
        prefix_sum[i] = prefix_sum[i - 1] + a[i];  
	    }  
  
    // 初始化 dp[i][1]  
    for (int i = 1; i <= n; ++i) {  
        dp[1][i] = prefix_sum[i];  
    }  
  
    for (int j = 2; j <= m; ++j) { // 分段数  
        for (int i = j; i <= n; ++i) { // 长度  
            dp[j % 2][i] = INT_MAX; // 重置当前状态  
            for (int k = j - 1; k < i; ++k) {  
                dp[j % 2][i] = min(dp[j % 2][i], max(dp[(j - 1) % 2][k], prefix_sum[i] - prefix_sum[k]));  
            }  
        }  
    }  
  
    cout << dp[m % 2][n] << endl; // 最终答案  
    return 0;  
} 
