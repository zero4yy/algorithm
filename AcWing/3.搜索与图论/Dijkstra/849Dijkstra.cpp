// 朴素版Dijkstra
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 0 ; i < n; i ++) {
        int t = -1;
        // 在所有未确定的点中，寻找具有最短距离的点
        for(int j = 1; j <= n; j ++) 
            if(!st[j] && (t == -1 || dist[t] > dist[j])) 
                t = j;
        // 所有点都已确定，退出循环
        if(t == -1) break;
        
        st[t] = true;
        
        for(int j = 1; j <= n; j ++) 
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z); //消除自环和重边的影响
    }

    int t = dijkstra();

    cout << t << endl;
    return 0;
}
