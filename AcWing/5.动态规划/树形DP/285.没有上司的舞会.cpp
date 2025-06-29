// https://www.acwing.com/problem/content/287/
/*

                                 |---集合：f(u,0)所有从以 u 为根的子树中选, 并且不选 u 这个点的方案
                                 |       ：f(u,1)所有从以 u 为根的子树中选, 并且选择 u 这个点的方案
     |---状态表示f(u,0)和f(0,1)---|
     |                           |---属性：max
     |
DP---|
     |
     |             |  
     |---状态计算---|  f(u,0) = sum max(f(s_i, 0), f(s_i, 1))
                   |  f(u,1) = sum f(s_i, 0)

O(n) 复杂度
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 6010;

int n;
int happy[N];
int h[N], e[N], ne[N], idx;
int f[N][2];
int has_father[N];
vector<int> g[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    f[u][1] = happy[u];

    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

void solve() {
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        has_father[a] = true;
        add(b, a);
    }

    int root = 1;
    while(has_father[root]) root ++;

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;
}

void dfs1(int u) {
    f[u][1] = happy[u];

    for(auto &j : g[u]) {
        dfs1(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

void solve1() {
    // 用 vector 存
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        has_father[a] = true;
    }
    int root = 1;
    while(has_father[root]) root ++;

    dfs1(root);

    cout << max(f[root][0], f[root][1]) << endl;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> happy[i];
    solve1();

    return 0;
}