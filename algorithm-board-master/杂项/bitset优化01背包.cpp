// https://www.luogu.com.cn/problem/CF577B
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

bitset<1000> b;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= m;
        b = b | (b << a) | (b >> (m - a));
        b[a] = 1;
    }
    cout << (b[0] ? "YES" : "NO") << endl;
    return 0;
}
