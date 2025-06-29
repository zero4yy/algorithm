// https://www.luogu.com.cn/problem/CF1207F
#include <bits/stdc++.h>
// #define int long long
#define endl '\n'

using namespace std;

int a[500001];
int d[1001][1001];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int q;
    cin >> q;
    int m = sqrt(500000);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            a[x] += y;
            for (int i = 1; i <= m; i++) {
                d[i][x % i] += y;
            }
        } else {
            if (x > m) {
                int res = 0;
                for (int i = y; i <= 500000; i += x) {
                    res += a[i];
                }
                cout << res << endl;
            } else {
                cout << d[x][y] << endl;
            }
        }
    }
    return 0;
}
