#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int n, k;
int p[10005][10005];
/*
n = y1 + y2 + y3 + ... + yk
1.  至少有1个1, n-1 = y1 + y2 + ... + yk-1, 即p(n-1, k-1)
2.  都大于1, n-k = y1 + y2 + ... + yk, 即p(n-k, k)
故dp方程: p(n,k) = p(n-1,k-1) + p(n-k,k)
*/
void work() {
    memset(p, 0, sizeof p);
    p[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i >= j) {
                p[i][j] = (p[i - 1][j - 1] + p[i - j][j]) % mod;
            }
        }
    }
    cout << p[n][k] << endl;
}
int main() {
    while(cin >> n >> k) {
        work();
    }
    return 0;
}