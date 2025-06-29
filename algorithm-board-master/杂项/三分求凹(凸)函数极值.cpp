// https://www.luogu.com.cn/problem/P3382
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;


int n;
double l, r;
vector<double> a;

double f(double x) {
    double res = 0;
    for (int i = n; i >= 1; i--) {
        res += a[i] * pow(x, i);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n >> l >> r;
    a = vector<double> (n + 1);
    for (int i = n; i >= 1; i--) {
        cin >> a[i];
    }
    double eps = 1e-9;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        double l_mid = mid - eps;
        double r_mid = mid + eps;
        if (f(l_mid) > f(r_mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}
