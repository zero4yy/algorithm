#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;
int d[N], q[N];
int n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int bfs() {
    int hh = 0, tt = 0;
    q[0] = 1;

    memset(d, -1, sizeof d);
    
    d[1] = 0;
    
    while(hh <= tt) {
        int t = q[hh ++];
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(d[j] == -1) {
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    return d[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    while(m --) {
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs();
    return 0;
}