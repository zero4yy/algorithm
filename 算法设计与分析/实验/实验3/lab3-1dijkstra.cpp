//用Dijkstra贪心算法求解单源最短路径问题
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl '\n'
const int N = 1e5 + 9;
using namespace std;
int dist[N];
bool vis[N];
vector<vector<int> >graph;
void dijkstra(int s) {
    int n = graph.size();
    memset(dist, 0x3f, n * sizeof(int));
    memset(vis, false, n * sizeof(bool));
    dist[s] = 0;
    
    for(int i = 0; i < n; i++) {
        int minDist = INF, u = -1;
        // 选择距离源点最近的未访问顶点。
        for(int  j = 0; j < n; j++) { 
            if(!vis[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if(u == -1) return;

        vis[u] = true;

        // 更新其相邻点的最短路径。
        for(int v = 0; v < n; v++) { 
            if(!vis[v] && dist[v] > dist[u] + graph[u][v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}
int main() {
    int s;
    graph={
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {INF, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };
    s = 0;
    dijkstra(s);
    // 输出每个顶点的最短路径
    for (int i = 0; i < graph.size(); i++) {
        if (dist[i] == INF)  // 如果dist[i]仍为无穷大，说明不可达
            cout << "dist[" << i << "]: INF" << endl;
        else
            cout << "dist[" << i << "]: " << dist[i] << endl;
    }
    return 0;
}