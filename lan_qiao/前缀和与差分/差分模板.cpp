//
// Created by Luzius on 2024/3/24.
//
//acwing 797
#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e5 + 5;
using namespace std;
int n, m, l, r, c;
ll a[N], b[N];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    for(int j = 1; j <= m; j++) {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + b[i];
        cout << a[i] << ' ';
    }

}
