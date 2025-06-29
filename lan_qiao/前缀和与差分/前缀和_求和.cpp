//
// Created by Luzius on 2024/2/27.
//
//https://www.lanqiao.cn/problems/2080/learning/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll ans = 0;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    vector<ll> sum(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 2; i <= n; i++)ans += a[i] * sum[i - 1];
    cout << ans;
    return 0;
}