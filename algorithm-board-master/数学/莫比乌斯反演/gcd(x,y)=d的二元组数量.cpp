// https://www.luogu.com.cn/problem/P3455
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> vis, p, mu;

void init(int n) {
    vis = vector<int> (n + 1);
    mu = vector<int> (n + 1);
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p.push_back(i);
            mu[i] = -1;
        }
        for (int j = 0; i * p[j] <= n; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) {
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        mu[i] += mu[i - 1];
    }
}

int calc(int n, int m, int k) {
    if (n > m) swap(n, m);
    n = n / k, m = m / k;
    int res = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        res += (mu[r] - mu[l - 1]) * (n / l) * (m / l);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    init(50005);
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << calc(n, m, k) << endl;
    }
    return 0;
}
