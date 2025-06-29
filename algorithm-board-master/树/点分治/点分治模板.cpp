/*
https://www.luogu.com.cn/problem/P3806
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
int root, mxs, sum, inf = 1e7 + 1;

vector<int> del, siz, dis, ask;
vector<int> judge;
vector<vector<vector<int>>> adj;
vector<int> q1, q2;
set<int> ok;

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
    q1.push_back(dis[x]);
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa || del[y]) continue;
        dis[y] = dis[x] + w;
        get_dis(y, x);
    }
}

void calc(int x) {
    judge[0] = 1;
    q2.clear();
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (del[y]) continue;
        dis[y] = w;
        q1.clear();
        get_dis(y, x);
        for (int j = 0; j < q1.size(); j++) {
            for (int k = 0; k < m; k++) {
                if (ask[k] >= q1[j] && judge[ask[k] - q1[j]]) {
                    ok.insert(k);
                }
            }
        }
        for (int j = 0; j < q1.size(); j++) {
            if (q1[j] < inf) {
                q2.push_back(q1[j]);
                judge[q1[j]] = 1;
            }
        }
    }
    for (int i = 0; i < q2.size(); i++) {
        judge[q2[i]] = 0;
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
    cin >> n >> m;
    del = vector<int> (n + 1);
    siz = vector<int> (n + 1);
    dis = vector<int> (n + 1);
    adj = vector<vector<vector<int>>> (n + 1);
    ask = vector<int> (m);
    judge = vector<int> (inf);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < m; i++) {
        cin >> ask[i];
    }
    mxs = sum = n;
    get_root(1, 0);
    get_root(root, 0);
    divide(root);
    for (int i = 0; i < m; i++) {
        if (ok.count(i)) {
            cout << "AYE" << endl;
        } else {
            cout << "NAY" << endl;
        }
    }
    return 0;
}
