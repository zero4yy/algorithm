//0-1背包
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N = 5005;
ll dp[N][N], v[N], w[N];
ll n, c;
void solve() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= c; ++j) {
            if(j < w[i]) 
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = max(
                    dp[i - 1][j - w[i]] + v[i],
                    dp[i-1][j]
                );
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    solve();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= c; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}