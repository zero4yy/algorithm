//
// Created by Luzius on 2024/1/29.
//
#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}//最小公倍数
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}//最大公约数
int main(){
    ll a, b;
    cin >> a >> b;
    cout << __gcd(a,b) << ' ' << gcd(a, b) << ' ' << lcm(a, b);
    return 0;
}
