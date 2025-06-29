#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m;
int dxi, dyi, dx = 0, dy = 0, x, y;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    cin >> n >> m;
    int i;
    for(i = 0; i < n; i++) {
        cin >> dxi >> dyi;
        dx += dxi;
        dy += dyi;
    }
    for(i = 0; i < m; i++) {
        cin >> x >> y;
        cout << (x + dx) << ' ' << (y + dy) << '\n';
    }
    return 0;
}