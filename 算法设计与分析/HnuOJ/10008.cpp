#include <set>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <cstdio>
#include <string>
#include <bitset>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ins insert
#define Vector Point
#define lowbit(x) (x&(-x))
#define mkp(x,y) make_pair(x,y)
#define mem(a,x) memset(a,x,sizeof a);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
const double eps=1e-8;
const double pi=acos(-1.0);
const int inf=0x3f3f3f3f;
const double dinf=1e300;
const ll INF=1e18;
const int Mod=1e9+7;
const int maxn=2e5+10;

char s[1005][1005];

int qkp(int x,int n){
    int ans=1;
    while(n){
        if(n&1) ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}

void dfs(int cur,int x,int y){
    if(cur==1){
        s[x][y]='X';
        return;
    }
    int d=qkp(3,cur-2);
    dfs(cur-1,x,y);
    dfs(cur-1,x,y+2*d);
    dfs(cur-1,x+d,y+d);
    dfs(cur-1,x+2*d,y);
    dfs(cur-1,x+2*d,y+2*d);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        if(n==-1) break;
        fill(s[0],s[0]+1000*1000,' ');
        dfs(n,1,1);
        int m=qkp(3,n-1);
        for(int i=1;i<=m;i++){
            for(int j=m;j>=1;j--)
                if(s[i][j]=='X'){
                    s[i][j+1]='\0';
                    break;
                }
        }
        for(int i=1;i<=m;i++) printf("%s\n",s[i]+1);
        printf("-\n");
    }
    return 0;
}