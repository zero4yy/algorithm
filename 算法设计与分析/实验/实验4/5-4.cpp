#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
#define MAX 10000
int MAP[MAX][MAX]; // �洢��Ů�˶�Ա�ľ������ƾ���
int cx[MAX];       // �洢ÿ��Ů�˶�Աƥ�䵽�����˶�Ա
int visx[MAX],visy[MAX],wy[MAX],wx[MAX]; // visx, visy�ֱ��ʾ�С�Ů�˶�Ա�Ƿ��ѷ��ʣ�wx, wy���С�Ů�˶�Ա��Ǳ��ֵ
int slack;         // ���ڼ�¼��ǰ���ɳ�ֵ
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