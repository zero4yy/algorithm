#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = 10005;
int n, m, k;
int dist[N], last[N];

struct Edge {
    int a, b, w;
}edges[M];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= k; i ++) {
        memcpy(last, dist, sizeof dist);
        for(int j = 1; j <= m; j ++) {
            auto e = edges[j];
            
            int a = e.a, b = e.b, w = e.w;
            dist[b] = min(dist[b], last[a] + w);   
        }
    }
    return;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    bellman_ford();
    if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
    return 0;
}