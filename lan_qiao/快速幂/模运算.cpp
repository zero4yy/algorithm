//
// Created by Luzius on 2024/2/1.
//
//求a^b mod m

#include<iostream>
using namespace std;
typedef long long ll;
ll m;
//01分治法实现
//ll fastpow(ll a, ll b)
//{
//    if(b == 0)return 1; //a^0 = 1
//    if(b == 1)return a % m;
//    ll t = fastpow(a, b / 2);
//    if(b & 1)return t % m * t % m * a % m; //奇数个a
//    else return t % m * t % m ; //偶数个a
//}
//02快速幂实现
ll fastpow(ll a, ll b)
{
    ll ans = 1;
    a %= m; //防止a*a越界
    while(b){
        if(b&1)ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ll a, b;
    cin >> a >> b >> m;
    cout << a << "^" << b << " mod " << m << "=" << fastpow(a, b);
}
