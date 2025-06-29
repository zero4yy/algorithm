// https://atcoder.jp/contests/abc368/tasks/abc368_f
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<int> divide(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            res.push_back(i);
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    // 打表代码
    // vector<int> sg(44);
    // sg[1] = 0;
    // for (int i = 2; i <= 40; i++) {
    //     set<int> s;
    //     for (int j = 1; j <= i - 1; j++) {
    //         if (i % j == 0) {
    //             s.insert(sg[j]);
    //         }
    //     }
    //     while (s.count(sg[i])) {
    //         sg[i]++;
    //     }
    // }
    // for (int i = 1; i <= 40; i++) {
    //     cout << i << ' ' << sg[i] << endl;
    // }
    int N = 100000;
    vector<int> sg(N + 1);
    for (int i = 2; i <= N; i++) {
        sg[i] = divide(i).size();
    }
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        res ^= sg[a];
    }
    cout << (res == 0 ? "Bruno" : "Anna") << endl;
    return 0;
}
