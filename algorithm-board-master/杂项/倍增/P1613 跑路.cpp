// https://www.luogu.com.cn/problem/P1613
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (64)));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dp[u][v][0] = 1;
    }
    for (int k = 1; k < 64; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int o = 1; o <= n; o++) {
                    if (dp[i][o][k - 1] && dp[o][j][k - 1]) {
                        dp[i][j][k] = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> f(n + 1, vector<int> (n + 1, 1e18));
    for (int k = 0; k < 64; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j][k]) {
                    f[i][j] = 1;
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
