// 矩阵重塑（一） 100
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int n, m, p, q;
int A[N];
int main() {
    cin >> n >> m >> p >> q;
    // 直接输出大法
    // for(int i = 0; i < n * m; i ++) {
    //     cin >> A[i];
    //     cout << A[i] <<' ';
    //     if((i + 1) % q == 0) cout << endl;
    // }

    for(int i = 0; i < n * m; i ++) cin >> A[i];
    for(int i = 0; i < p; i ++) {
        for(int j = 0; j < q; j ++) {
            cout << A[i * q + j] << ' ';
        }
        cout << endl;
    }
    return 0;
}