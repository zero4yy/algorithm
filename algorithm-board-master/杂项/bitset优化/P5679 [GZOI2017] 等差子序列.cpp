// https://www.luogu.com.cn/problem/P5679
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int C = 40001, D = 20000;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> cnt(C);
    bitset<C> l, r;
    for (int i = 1; i < n; i++) {
        cnt[D - a[i]]++;
        r[D - a[i]] = 1;
    }
    for (int i = 1; i < n; i++) {
        l[D + a[i - 1]] = 1;
        cnt[D - a[i]]--;
        if (cnt[D - a[i]] == 0) r[D - a[i]] = 0;
        bitset<C> t = l & (r << (2 * a[i]));
        if (t.any()) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
