/*
dis = |x1 - x2| + |y1 - y2|
= max{x1 - x2 + y1 - y2, x1 - x2 + y2 - y1, x2 - x1 + y1 - y2, x2 - x1 + y2 - y1}
= max{|(x1 + y1) - (x2 + y2)|, |(x1 - y1) - (x2 - y2)|}

曼哈顿转切比雪夫:
点(x,y)转化为(x+y,x-y),原点的曼哈顿距离等于新点的切比雪夫距离

切比雪夫转曼哈顿
点(x,y)转化为((x+y)/2,(x-y)/2)
*/

// https://www.luogu.com.cn/problem/P3964
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    vector<int> tx(n + 1), ty(n + 1);
    vector<int> pre_x(n + 1), pre_y(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        x[i] = tx[i] = a + b;
        y[i] = ty[i] = a - b;
    }
    sort(tx.begin() + 1, tx.end());
    sort(ty.begin() + 1, ty.end());
    for (int i = 1; i <= n; i++) {
        pre_x[i] = pre_x[i - 1] + tx[i];
        pre_y[i] = pre_y[i - 1] + ty[i];
    }
    int res = 1e18;
    for (int i = 1; i <= n; i++) {
        int px = lower_bound(tx.begin() + 1, tx.end(), x[i]) - tx.begin();
        int py = lower_bound(ty.begin() + 1, ty.end(), y[i]) - ty.begin();
        int sum_x = px * x[i] - pre_x[px] + pre_x[n] - pre_x[px] - (n - px) * x[i];
        int sum_y = py * y[i] - pre_y[py] + pre_y[n] - pre_y[py] - (n - py) * y[i];
        res = min(res, sum_x + sum_y);
    }
    cout << res / 2 << endl;
    return 0;
}
