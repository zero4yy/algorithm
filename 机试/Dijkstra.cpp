#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

void dfs() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= n; i ++) {
        int idx = -1;
        for(int j = 1; j <= n; j ++) {
            if(!st[j] && (idx == -1 || dist[j] < dist[idx])) 
                idx = j;
        }

        if(idx == -1) break;
        st[idx] = true;

        for(int i = 1; i <= n; i ++) {
            if(!st[i]) {
                if(dist[i] > dist[idx] + g[idx][i])
                    dist[i] = dist[idx] + g[idx][i];
            }
        }

    }
    return;

}
void dfs_heap() {
    
}
int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    dfs();
    if(dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];

    return 0;
}