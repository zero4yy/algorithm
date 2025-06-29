// https://www.luogu.com.cn/problem/P2495
// https://loj.ac/p/3789
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct LCA {

    int T;
    vector<int> depth, dfn;
    vector<vector<int>> g, fa;

    LCA() {}
    LCA(int n) {    // 构造函数,传入点数
        T = 1;
        depth = vector<int> (n + 5, 1e9);
        dfn = vector<int> (n + 5);
        g = vector<vector<int>> (n + 5);
        fa = vector<vector<int>> (n + 5);
    }

    void add(int u, int v) {    // 添加一条无向边
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void init(int x, int f, vector<int>& path, int deep) {    // 传入root, -1, {}, 1
        dfn[x] = T++;
        depth[x] = deep;
        for (int i = 1; i <= path.size(); i *= 2) {
            fa[x].push_back(path[path.size() - i]);
        }
        path.push_back(x);
        for (int y : g[x]) {
            if (y == f) continue;
            init(y, x, path, deep + 1);
        }
        path.pop_back();
    }

    int lca(int a, int b) { // 获取a和b的最近公共祖先
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = 18; i >= 0; i--) {
            if (i < fa[a].size() && depth[fa[a][i]] >= depth[b]) {
                a = fa[a][i];
            }
        }
        if (a == b) return a;
        for (int i = 18; i >= 0; i--) {
            if (i < fa[a].size() && i < fa[b].size() && fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    }

    int getDist(int a, int b) { // 获取a和b之间的距离
        int lca_ab = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[lca_ab];
    }

    int getKthAncestor(int x, int k) {  // 返回结点x的第k个祖先
        for (int i = 0; i < 18; i++) {
            if (k & (1 << i) && i < fa[x].size()) {
                x = fa[x][i];
                k -= 1 << i;
            }
        }
        if (k != 0) return -1;
        return x;
    }
};

struct VirtualTree {

    int n;
    LCA L;
    vector<int> siz;    // siz[i] > 0表示i是关键点
    vector<vector<vector<int>>> adj;    // 虚树
    vector<int> all;    // 虚树上的所有点

    VirtualTree() {}
    VirtualTree(int n) {
        this->n = n;
        L = LCA(n);
        siz = vector<int> (n + 1);
        adj = vector<vector<vector<int>>> (n + 1);
    }

    void add(int u, int v) {    // 添加一条无向边, 预处理lca用
        L.add(u, v);
    }

    // vector<int> point;  // 关键点
    void build_virtual_tree(vector<int>& point) {
        point.push_back(1); // 根节点入栈, 保证图联通
        sort(point.begin(), point.end(), [&](int x, int y) {    // 把关键点按照 dfn 序排序
            return L.dfn[x] < L.dfn[y];
        });
        for (int i = 0; i < (int)point.size() - 1; i++) {
            all.push_back(point[i]);
            all.push_back(L.lca(point[i], point[i + 1]));         // 插入 lca
        }
        all.push_back(point.back());
        sort(all.begin(), all.end(), [&](int x, int y) {            // 把所有虚树上的点按照 dfn 序排序
            return L.dfn[x] < L.dfn[y];
        });
        all.erase(unique(all.begin(), all.end()), all.end());
        for (int i = 0; i < (int)all.size() - 1; i++) {
            int lc = L.lca(all[i], all[i + 1]);
            int w = 1;  // 如有边权, 先算边权
            adj[lc].push_back({all[i + 1], w});
            adj[all[i + 1]].push_back({lc, w});
        }
    }

    void clear() {
        for (int i = 0; i < all.size(); i++) {
            siz[all[i]] = 0;
            adj[all[i]].clear();
        }
        all.clear();
    }
};

VirtualTree V;

vector<vector<vector<int>>> adj;
vector<int> pre;
void init(int x, int fa, int v) {
    pre[x] = v;
    for (int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i][0], w = adj[x][i][1];
        if (y == fa) continue;
        init(y, x, min(v, w));
    }
}

int dfs(int x, int fa) {
    if (V.siz[x]) { // 是关键点
        return pre[x];
    } else {        // 不是关键点
        int res = 0;
        for (int i = 0; i < adj[x].size(); i++) {
            int y = adj[x][i][0], w = adj[x][i][1];
            if (y == fa) continue;
            res += dfs(y, x);
        }
        return min(res, pre[x]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    adj = vector<vector<vector<int>>> (n + 1);
    pre = vector<int> (n + 1, 1e18);
    V = VirtualTree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        V.add(u, v);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    init(1, -1, 1e18);
    vector<int> path;
    V.L.init(1, -1, path, 1);
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> point(k);
        for (int i = 0; i < k; i++) {
            cin >> point[i];
            V.siz[point[i]] = 1;
        }
        V.build_virtual_tree(point);
        cout << dfs(1, -1) << endl;
        V.clear();
    }
    return 0;
}
