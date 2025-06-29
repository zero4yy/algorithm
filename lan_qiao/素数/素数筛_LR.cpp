//
// Created by Luzius on 2024/2/1.
//
//https://www.luogu.com.cn/problem/P1835
#include<iostream>
#include<cmath>
#include<cstring>
typedef long long ll;
using namespace std;
const int N = 1e6 + 5;
int L, R;
int prime[50000];
bool visit[N];
int E_sieve(int n){
    int k = 0;
    for(int i = 2; i <= sqrt(n); i++)
        if(!visit[i])
            for(int j = i*i; j <= n; j += i)
                visit[j] = true;
    for(int i = 2; i <= n; i++)
        if(!visit[i])prime[++k] = i;
    return k;
}
int main(){
    cin >> L >> R;
    if(L == R){cout << 0; return 0;}
    if(L == 1)L = 2;
    int k = E_sieve(50000);
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= k; i++){
        int p = prime[i];
        ll j = 2*p;
        if(L > j) j = (L - 1 + p) / p * p;  //此步很重要，要想清楚
        for(; j <= R; j += p) visit[j - L + 1] = true;
    }
    int ans = 0;
    for(int i = 1; i <= R - L + 1; i++)
        if(!(visit[i])) ans++;
    cout << ans;
}