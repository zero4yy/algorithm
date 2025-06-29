#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define PI acos(-1.0)
#define E 1e-9
#define INF 0x3f3f3f3f
#define LL long long
const int MOD=1E9+7;
const int N=10000+5;
const int dx[]= {-1,1,0,0};
const int dy[]= {0,0,-1,1};
using namespace std;
 
bool vis[N];//vis[i]表示是否在交替路中
int link[N];//存储连接点
vector<int> G[N];//存边
bool dfs(int x){
    for(int i=0;i<G[x].size();i++){
        int y=G[x][i];
        if(!vis[y]){//不在交替路中
            vis[y]=true;//放入交替路
            if(link[y]==-1 || dfs(link[y])){//如果是未匹配点，说明交替路是增广路
                link[y]=x;//交换路径
                return true;//返回成功
            }
        }
    }
    return false;//不存在增广路，返回失败
}
int hungarian(int x){
    int ans=0;//记录最大匹配数
    for(int i=1;i<=x;i++){//从左侧开始每个结点找一次增广路
        memset(vis,false,sizeof(vis));
        if(dfs(i))//找到一条增广路，形成一个新匹配
            ans++;
    }
    return ans;
}
int main(){
    int n,m,k;
    while(scanf("%d",&n)!=EOF&&(n)){
        scanf("%d%d",&m,&k);
        memset(link,-1,sizeof(link));
        for(int i=0;i<n;i++)
            G[i].clear();
 
        while(k--){
            int i,x,y;
            scanf("%d%d%d",&i,&x,&y);
            if(x==0||y==0)
                continue;
            G[x].push_back(y);
        }
 
        printf("%d\n",hungarian(n-1));
    }
    return 0;
}