/*
https://www.luogu.com.cn/problem/P2634
https://space.bilibili.com/517494241?spm_id_from=333.788.0.0
点分治四部操作
1.找出树的重心做根, get_root()
2.求出子树中的各点到根的距离, get_dis()
3.对当前树统计答案, calc()
4.分治各个子树, 重复以上操作, divide()
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int n, m;
int root, mxs, sum;

vector<int> del, siz, dis;
vector<vector<vector<int>>> adj;
vector<int> q1, q2;
int res = 0;

void get_root(int x, int fa) {
    siz[x] = 1;
    int s = 0;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        get_root(y, x);
        siz[x] += siz[y];
        s = max(s, siz[y]);
    }
    s = max(s, sum - siz[x]);
    if (s < mxs) {
        mxs = s;
        root = x;
    }
}

void get_dis(int x, int fa) {
    q1[dis[x] % 3]++;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        dis[y] = (dis[x] + w) % 3;
        get_dis(y, x);
    }
}

void calc(int x) {
    q2 = vector<int> (3);
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        dis[y] = w;
        q1 = vector<int> (3);
        get_dis(y, x);
        res += q1[0] * q2[0] * 2;
        res += q1[1] * q2[2] * 2;
        res += q1[2] * q2[1] * 2;
        res += q1[0] * 2;
        q2[0] += q1[0];
        q2[1] += q1[1];
        q2[2] += q1[2];
    }
}

void divide(int x) {
    calc(x);
    del[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        mxs = sum = siz[y];
        get_root(y, 0);
        divide(root);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n;
    del = vector<int> (n + 1);
    siz = vector<int> (n + 1);
    dis = vector<int> (n + 1);
    adj = vector<vector<vector<int>>> (n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    mxs = sum = n;
    get_root(1, 0);
    get_root(root, 0);
    divide(root);
    res += n;
    int t = __gcd(res, n * n);
    cout << res / t << '/' << n * n / t << endl;
    return 0;
}
