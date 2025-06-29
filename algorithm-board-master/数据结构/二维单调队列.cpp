// https://www.luogu.com.cn/problem/CF1195E
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int x, y, z;
    vector<int> g((n + 1) * (m + 1));
    cin >> g[0] >> x >> y >> z;
    for (int i = 1; i <= n * m; i++) {
        g[i] = (g[i - 1] * x + y) % z;
    }
    vector<vector<int>> h(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            h[i][j] = g[(i - 1) * m + j - 1];
        }
    }
    vector<vector<int>> left(n + 1, vector<int> (m + 1, 1e18));
    vector<vector<int>> down(n + 1, vector<int> (m + 1, 1e18));
    for (int i = 1; i <= n; i++) {
        deque<int> q;
        for (int j = 1; j <= m; j++) {
            while (q.size() && q.front() + b <= j) {
                q.pop_front();
            }
            while (q.size() && h[i][j] < h[i][q.back()]) {
                q.pop_back();
            }
            q.push_back(j);
            left[i][j] = h[i][q.front()];
        }
    }
    for (int j = 1; j <= m; j++) {
        deque<int> q;
        for (int i = 1; i <= n; i++) {
            while (q.size() && q.front() + a <= i) {
                q.pop_front();
            }
            while (q.size() && left[i][j] < left[q.back()][j]) {
                q.pop_back();
            }
            q.push_back(i);
            down[i][j] = left[q.front()][j];
        }
    }
    int res = 0;
    for (int i = a; i <= n; i++) {
        for (int j = b; j <= m; j++) {
            res += down[i][j];
        }
    }
    cout << res << endl;
    return 0;
}