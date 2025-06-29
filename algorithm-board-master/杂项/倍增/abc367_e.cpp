// https://atcoder.jp/contests/abc367/tasks/abc367_e
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> st(n, vector<int> (61));
    for (int i = 0; i < n; i++) {
        cin >> st[i][0];
        st[i][0]--;
    }
    for(int i = 1; i <= 60; i++) {
        for(int j = 0; j < n; j++) {
            st[j][i] = st[st[j][i - 1]][i - 1];
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < 60; j++) {
            if (k >> j & 1) {
                x = st[x][j];
            }
        }
        cout << a[x] << ' ';
    }
    cout << endl;
    return 0;
}
