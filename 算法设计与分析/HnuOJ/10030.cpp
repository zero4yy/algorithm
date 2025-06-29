#include<map>
#include<iostream>
#include<cstring>
#include<time.h>
#include<cstdlib>
using namespace std;
const int M=10000,N=52;
typedef long long ll;
int st[28][N],m[28],x,i,b[28],le[128],n,j;
char S[N];
string s;
ll num[N],t;
void work(int id){
    int cnt=0,top=0;
    for (int i=0;s[i];i++){
        if (s[i]=='a') st[id][++cnt]=-1;
        else if ('0'<=s[i] && s[i]<='9'){
            int j=i,x=0;
            while ('0'<=s[j] && s[j]<='9') x=(x<<3)+(x<<1)+(s[j++]^48);
            i=j-1;st[id][++cnt]=x;
        }else if (s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='^'){
            while (top && S[top]!='(' && le[s[i]]<=le[S[top]]) st[id][++cnt]=S[top--]+M;
            S[++top]=s[i];
        }else if (s[i]==')'){
            while (top && S[top]!='(') st[id][++cnt]=S[top--]+M;
            top--;
        }
    }
    while (top){
        if (S[top]!='(') st[id][++cnt]=S[top]+M;
        top--;
    }
    m[id]=cnt;
}
ll power(ll x,ll y){
    ll res=1;
    for (;y;y>>=1,x*=x)
        if (y&1) res*=x;
    return res;
}
ll Cal(ll x,ll y,char c){
    if (c=='+') return x+y;
    if (c=='-') return x-y;
    if (c=='*') return x*y;
    return power(x,y);//不知道为什么，不能用pow(x,y)
}
ll calc(int id,int a){
    int top=0;
    for (int i=1;i<=m[id];i++){
        if (st[id][i]==-1) num[++top]=a;
        else if (st[id][i]>M){
            ll res=Cal(num[top-1],num[top],st[id][i]-M);
            num[--top]=res;
        }else num[++top]=st[id][i];
    }
    return num[1];
}
int main(){
    le['*']=1;le['^']=2;le['(']=le[')']=3;
    getline(cin,s);work(0);
    scanf("%d\n",&n);
    for (i=1;i<=n;i++) getline(cin,s),work(i);
    for (i=0;i<100;i++){
        x=rand();
        t=calc(0,x);
        for (j=1;j<=n;j++)
            if (!b[j] && calc(j,x)!=t) b[j]=1;
    }
    for (i=1;i<=n;i++)
        if (!b[i]) putchar('A'+i-1);
}