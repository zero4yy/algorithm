// https://ac.nowcoder.com/acm/contest/74362/D
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    map<int, int> l, r;
    int q;
    cin >> q;
    int begin = -1, end = -2;
    r[begin] = end;
    l[end] = begin;
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (y == 0) {
                y = begin;
            }
            r[x] = r[y];
            l[r[y]] = x;
            r[y] = x;
            l[x] = y;
        } else {
            cin >> x;
            l[r[x]] = l[x];
            r[l[x]] = r[x];
        }
    }
    vector<int> res;
    while (begin != end) {
        res.push_back(begin);
        begin = r[begin];
    }
    cout << res.size() - 1 << endl;
    for (int i = 1; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}
