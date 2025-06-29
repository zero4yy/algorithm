//优先队列实现Dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl '\n'
#define PII pair<int, int>
const int N = 1e5 + 9;
using namespace std;
int dist[N];
bool vis[N];
vector<vector<PII> >graph;
priority_queue<PII, vector<PII>, greater<PII>> pq;

void dijkstra(int s) {
    int n = graph.size();
    memset(dist, 0x3f, n * sizeof(int));
    memset(vis, false, n * sizeof(bool));
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

}
int main() {
    int s;
    graph={
        {{1, 10}, {3, 30}, {4, 100}},// 顶点0到其他顶点的边
        {{2, 50}},
        {{4, 10}},
        {{2, 20}, {4, 60}},
        {}
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