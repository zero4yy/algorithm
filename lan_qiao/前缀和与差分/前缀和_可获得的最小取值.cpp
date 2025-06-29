//
// Created by Luzius on 2024/2/27.
//
//https://www.lanqiao.cn/problems/3142/learning/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n, k;
ll a[N], s[N];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
    ll ans = 1e18;
    for(int p = 1; p <= k; p++)ans = min(s[n] - s[n - k + p] + s[2 * p], ans);
    cout << ans;
    return 0;
}