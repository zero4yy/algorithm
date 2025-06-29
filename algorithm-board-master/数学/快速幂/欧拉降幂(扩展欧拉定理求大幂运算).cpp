// https://www.luogu.com.cn/problem/P5091
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int get_phi(int m) {    // 求欧拉函数O(sqrt(m))
    int res = m;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            res = res / i * (i - 1);
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) res = res / m * (m - 1);
    return res;
}

int depow(string& s, int phi) {    // 降幂, O(s.size())
    int b = 0, flag = 0;
    for (int i = 0; i < s.size(); i++) {
        b = b * 10 + (s[i] - '0');
        if (b >= phi) flag = 1, b %= phi;
    }
    if (flag) b += phi;
    return b;
}

int pow(int a, int b, int mod) {    // 快速幂
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int a, m;
    string s;
    cin >> a >> m >> s;
    int phi = get_phi(m);
    int b = depow(s, phi);
    cout << pow(a, b, m) << endl;
    return 0;
}
