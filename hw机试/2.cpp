#include <bits/stdc++.h>

using namespace std;
const int MAX = 0x3f3f3f3f;
int g[25][25];
int d[25];
int n, t;
bool vis[25];
void dfs() {
    d[0] = 0;
    for(int i = 1; i <= n; i ++) d[i] = g[0][i];
    for(int i = 1; i <= n; i ++) {
        int maxx = MAX;
        int idx = -1;

        // 寻找最小值 索引
        for(int j = 1; j <= n; j ++) {
            if(!vis[j]) {
                if (d[j] < maxx) {
                    maxx = d[j], idx = j;
                }
            }
        }
        if(idx == -1) break;
        vis[idx] = true;

        for(int k = 1; k <= n; k ++) {
            if(d[idx] + g[idx][k] < d[k]) 
                d[k] = d[idx] + g[idx][k];
        }
    }

}
int main() {
    cin >> n;
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= n; j ++) {
            cin >> g[i][j];
            if(g[i][j] == 0) g[i][j] = MAX;
        }
    }
    cin >> t;
    dfs();
    cout << d[t];
    return 0;
}

