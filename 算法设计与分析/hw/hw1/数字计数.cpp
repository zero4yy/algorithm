//https://www.luogu.com.cn/problem/P2602
#include<bits/stdc++.h>
typedef long long ll;
const int N = 15;
using namespace std;
ll n, m, dp[N], weight[N], ans1[N], ans2[N];
int a[N];
void solve(ll n, ll *ans) {
    ll _n = n;
    int len = 0;
    while(n) a[++len] = n % 10, n /= 10;

    for(int i = len; i >= 1; i--) {
        for(int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i]; //前i-1位的贡献
        for(int j = 0; j < a[i]; j++) ans[j] += weight[i - 1];  
        _n -= weight[i - 1] * a[i];
        ans[a[i]] += _n + 1;
        ans[0] -= weight[i - 1];
    }

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    weight[0] = 1ll;
    for(int i = 1; i <= 13; ++i) {
        dp[i] = dp[i - 1] * 10 + weight[i - 1];
        weight[i] = weight[i - 1] * 10;
    }
    solve(n - 1, ans1), solve(m, ans2);
    for(int i = 0; i < 10; i++) cout << ans2[i] - ans1[i] << ' ';
}
