// https://www.luogu.com.cn/problem/AT_dp_s
#include <bits/stdc++.h>

using namespace std;

string s;
int d, mod = 1e9 + 7;
int dp[10005][101][2][2];

int dfs(int pos, int sum, bool limit, bool full, string& s) {
    if (dp[pos][sum][limit][full] != -1) return dp[pos][sum][limit][full];
    if (pos == s.size()) return full && sum == 0;
    int res = 0;
    if (!full) res = (res + dfs(pos + 1, sum, false, false, s)) % mod;
    int now = s[pos] - '0';
    int down = full ? 0 : 1;
    int up = limit ? now : 9;
    for (int i = down; i <= up; i++) {
        res = (res + dfs(pos + 1, (sum + i) % d, limit && (i == now), true, s)) % mod;
    }
    return dp[pos][sum][limit][full] = res;
}

signed main() {
    cin >> s >> d;
    memset(dp, -1, sizeof dp);
    int res = dfs(0, 0, true, false, s);
    cout << res << endl;
}