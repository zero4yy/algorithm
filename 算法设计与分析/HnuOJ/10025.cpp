#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1005,mod=10000;
int k,p[maxn],e[maxn],f[maxn];
int mg(int x,int y){
    int t=1;
    while(y>0){
        if(y&1)t=t*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return t;
}
int main(){
    int ans1=0,ans2=0,ans3=1,i,j,op=1;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d%d",&p[i],&e[i]);
        if(p[i]==2)op=2;
    }
    f[0]=1;
    for(i=op;i<=k;i++)
        for(j=i-op+1;j;j--)
            f[j]=(f[j]+f[j-1]*(p[i]-1)%mod)%mod;
    for(i=1;i<=k-op+1;i++)
        if(i&1)ans2=(ans2+f[i])%mod;
        else ans1=(ans1+f[i])%mod;
    for(i=1;i<=k;i++)
        ans3=(ans3*mg(p[i],e[i]))%mod;
    ans3=(ans3-ans1-ans2-1+(mod<<4))%mod;
    cout<<ans1<<endl<<ans2<<endl<<ans3;
}