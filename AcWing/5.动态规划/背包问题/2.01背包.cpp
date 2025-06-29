#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;
int n, m;
int v[N], w[N];
int f[N][N];
int g[N];

void erwei() {
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(j < v[i]) 
                f[i][j] = f[i - 1][j];
            else 
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;
}

void yiwei() {
    for(int i = 1; i <= n; i ++) 
        for(int j = m; j >= v[i]; j --)
            g[j] = max(g[j], g[j - v[i]] + w[i]);
    
    cout << g[m] << endl;
}

//如果题目问：物品总体积恰好是m，的最大价值，只需g[0] = 0, g[j] = -1e9
void qiahao() {
    fill(g, g + m, -INF);
    g[0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= v[i]; j --) {
            g[j] = max(g[j], g[j - v[i]] + w[i]);
        }
    }
    
    cout << (g[m] < 0 ? -1 : g[m]) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];
    yiwei();

    return 0;
}