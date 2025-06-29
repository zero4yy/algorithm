/*
dis = |x1 - x2| + |y1 - y2|
= max{x1 - x2 + y1 - y2, x1 - x2 + y2 - y1, x2 - x1 + y1 - y2, x2 - x1 + y2 - y1}
= max{|(x1 + y1) - (x2 + y2)|, |(x1 - y1) - (x2 - y2)|}

曼哈顿转切比雪夫:
点(x,y)转化为(x+y,x-y),原点的曼哈顿距离等于新点的切比雪夫距离

切比雪夫转曼哈顿
点(x,y)转化为((x+y)/2,(x-y)/2)
*/

// https://www.luogu.com.cn/problem/P5098
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
    vector<vector<int>> a(n, vector<int> (2));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i][0] = x + y;
        a[i][1] = x - y;
    }
    int res = 0;
    sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
        return x[0] < y[0];
    });
    res = max(res, a[n - 1][0] - a[0][0]);
    sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
        return x[1] < y[1];
    });
    res = max(res, a[n - 1][1] - a[0][1]);
    cout << res << endl;
    return 0;
}
