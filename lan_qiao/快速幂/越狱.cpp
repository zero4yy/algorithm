//
// Created by Luzius on 2024/2/1.
//
//https://www.luogu.com.cn/problem/P3197
#include<iostream>
using namespace std;
typedef long long ll;
const int mod = 100003;
ll fpow(ll m, ll n)
{
    ll ans = 1;
    m %= mod;
    while(n)
    {
        if(n&1)ans = ans * m % mod;
        n >>= 1;
        m = m * m % mod;
    }
    return ans;
    
}

int main()
{
    ll m, n;
    cin >> m >> n;
    ll ans = fpow(m, n) - fpow(m - 1, n - 1) * m % mod;
    //cout << fpow(m, n) << " " << m % mod * fpow(m - 1, n - 1) % mod << '\n';
    if(ans < 0)ans += mod;
    cout << ans % mod;
}