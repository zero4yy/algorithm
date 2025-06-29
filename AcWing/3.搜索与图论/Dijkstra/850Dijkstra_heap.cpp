// 堆优化版Dijkstra
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 1000010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while(!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;

        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];

            if(dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m --) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }

    for(int i = 1; i <= n; i ++) {
        cout << "h" << i << endl;
        for(int j = h[i]; j != -1; j = ne[j]) {
            cout << e[j] << ' ' << ne[j] << endl;
        }
    }
    int t = dijkstra();

    cout << t << endl;
    return 0;
}
