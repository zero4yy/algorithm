#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N]; // 表示当前点是否在队列中

void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa() 
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();
        
        st[t] =false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j]) 
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);    
    }
    spfa();

    if(dist[n] == 0x3f3f3f3f) cout << "impossible\n";

    else cout << dist[n] << endl;

    return 0;
}