//
// Created by Luzius on 2024/2/1.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_prime(ll n){
    if(n <= 1)return false;
    for(ll i = 2; i * i <= n; i++)if(n % i == 0)return false;
    return true;
}
int main(){
    ll n; cin >> n;
    if(is_prime(n))cout << n << "是素数";
    else cout << n << "不是素数";
}