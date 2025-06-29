#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
#define pb(x) push_back(x)
#define ll long long
#define mk(x, y) make_pair(x, y)
#define lson l, m, rt<<1
#define mem(a) memset(a, 0, sizeof(a))
#define rson m+1, r, rt<<1|1
#define mem1(a) memset(a, -1, sizeof(a))
#define mem2(a) memset(a, 0x3f, sizeof(a))
#define rep(i, n, a) for(int i = a; i<n; i++)
#define fi first
#define se second
typedef pair<int, int> pll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9+7;
const int inf = 1061109567;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
const int maxn = 2e5+5;
int num, head[maxn*2], s, t, n, k, nn, flow, cnt, cap[maxn], q[maxn], cur[maxn], vis[maxn];
double cost, dis[maxn];
struct node
{
    int to, nextt, c;
    double w;
    node(){}
    node(int to, int nextt, int c, double w):to(to), nextt(nextt), c(c), w(w) {}
}e[maxn*2];
int spfa() {
    int st, ed;
    st = ed = 0;
    for(int i = 1; i<maxn; i++)
        dis[i] = -inf;
    ++cnt;
    dis[s] = 0;
    cap[s] = inf;
    cur[s] = -1;
    q[ed++] = s;
    while(st<ed) {
        int u = q[st++];
        vis[u] = cnt-1;
        for(int i = head[u]; ~i; i = e[i].nextt) {
            int v = e[i].to, c = e[i].c;
            double w = e[i].w;
            if(c && dis[v]<dis[u]+w&&fabs(dis[v]-dis[u]-w)>eps) {
                dis[v] = dis[u]+w;
                cap[v] = min(c, cap[u]);
                cur[v] = i;
                if(vis[v] != cnt) {
                    vis[v] = cnt;
                    q[ed++] = v;
                }
            }
        }
    }
    if(fabs(dis[t] + inf)<eps)
        return 0;
    cost += dis[t]*cap[t];
    flow += cap[t];
    for(int i = cur[t]; ~i; i = cur[e[i^1].to]) {
        e[i].c -= cap[t];
        e[i^1].c += cap[t];
    }
    return 1;
}
double mcmf() {
    flow = cost = 0;
    while(spfa())
        ;
    return cost;
}
void add(int u, int v, int c, double val) {
    e[num] = node(v, head[u], c, val); head[u] = num++;
    e[num] = node(u, head[v], 0, -val); head[v] = num++;
}
void init() {
    mem1(head);
    num = cnt = 0;
    mem(vis);
}
double a[maxn];
void deal(double ans){
    char ch[40];
    sprintf(ch,"%.15f\n",ans);
    int sum=0,i;
    for(i=0; sum<5; i++)
    {
        if((ch[i]!='0'&&ch[i]!='.')|sum>0)
            sum++;
    }
    if(ch[i]>='5')
        ch[i-1]++;
    ch[i]=0;
    for(; i>=0; i--)
    {
        if(ch[i]=='.')break;
        else if(ch[i]>'9') {
            ch[i-1]++,ch[i]='0';
        }
    }
    printf("%s\n",ch);
}
int main()
{
    init();
    int n, m, ss, x;
    cin>>n>>m;
    s = 0, ss = n+1, t = n+2;
    add(s, ss, m, log(1.0));
    for(int i = 1; i<=n; i++) {
        scanf("%lf", &a[i]);
    }
    for(int i = 1; i<=n; i++) {
        scanf("%d", &x);
        if(x) {
            add(ss, i, x, log(a[i]));
        }
    }
    for(int i = 1; i<=n; i++) {
        scanf("%d", &x);
        if(x)
            add(i, t, m, log(1.0));
    }
    int y, y1;
    double x1;
    while(scanf("%d%d", &x, &y)) {
        if(x==-1&&y==-1)
            break;
        scanf("%lf%d", &x1, &y1);
        add(x, y, y1, log(x1));
        add(y, x, y1, log(x1));
    }
    double ans = mcmf();
    if(flow!=m) {
        puts("0.0000\n");
        return 0;
    } else {
        ans = exp(ans);
        deal(ans);
    }
    return 0;
}