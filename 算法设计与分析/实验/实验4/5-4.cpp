#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
#define MAX 10000
int MAP[MAX][MAX]; // 存储男女运动员的竞赛优势矩阵
int cx[MAX];       // 存储每个女运动员匹配到的男运动员
int visx[MAX],visy[MAX],wy[MAX],wx[MAX]; // visx, visy分别表示男、女运动员是否已访问，wx, wy是男、女运动员的潜在值
int slack;         // 用于记录当前的松弛值
int n;
bool dfs(int u)
{
    visx[u] = 1;
    for(int v = 1; v <= n; v++)
    {
        if(!visy[v])
        {
            int t = wx[u] + wy[v] - MAP[u][v];
            if(t == 0)
            {
                visy[v] = 1;
                if(cx[v] == 0 || dfs(cx[v]))
                {
                    cx[v] = u;
                    return true;
                }
            }else if(t > 0) slack = min(slack,t);
        }
    }
    return false;
}

void KM()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            wx[i] = max(wx[i],MAP[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            slack = 100000000;
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(dfs(i)) break;
            for(int j = 1; j <= n; j++)
            {
                if(visx[j]) wx[j] -= slack;
            }
            for(int j = 1; j <= n; j++)
            {
                if(visy[j]) wy[j] += slack;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += MAP[cx[i]][i];
    }
    printf("%d",ans);
}
int main()
{
    freopen("in2.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>MAP[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int r;
            cin>>r;
            MAP[j][i] *= r;
        }
    }
    KM();
    return 0;
}