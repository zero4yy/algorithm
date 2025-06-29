//
// Created by Luzius on 2024/2/1.
//
//https://www.luogu.com.cn/problem/P1036
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, k;
ll ans = 0;
ll x[25];
bool isprime(ll y){
    if(y < 2)return false;
    for(ll i = 2; i * i <= y; i++)if(y % i == 0)return false;
    return true;
}
void dfs(int depth, int sum, ll res){
    if(sum == k){
        cout << res << endl;
        if(isprime(res)) ans++;
        return;
    }
    //或者：
    //if(depth > n)return;
    // dfs(depth + 1, sum + 1, res + x[depth]);
    // dfs(depth + 1, sum, res);
    for(int i = depth; i <= n; i++)
       dfs(i + 1, sum + 1, res + x[i]);
    return;
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> x[i];
    dfs(1, 0, 0);
    cout << ans;
}