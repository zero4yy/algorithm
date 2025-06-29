#include<bits/stdc++.h>
const int N = 1001;
const int M = 11;
#define endl '\n'
using namespace std;
int n, m, flag, ans;
int ck[N][M];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> ck[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == i) continue;
            flag = 1;
            for(int k = 1; k <= m; k++) {
                if(ck[i][k] >= ck[j][k]) {flag = 0;break;}
            }
            if(flag) {
                ans = j;
                break;
            } else {
                ans = 0;
            }
        }
        cout << ans << endl;
    }
}