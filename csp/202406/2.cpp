// 矩阵重塑（二） 100
// 关键：1维数组存储矩阵
// 好处：重塑并不影响 1 维数组
#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int n, m, t, op, x, y;
int a[N];

int main() {
    cin >> n >> m >> t;
    for(int i = 0; i < n * m; i ++) cin >> a[i];
    
    while(t --) {
        cin >> op >> x >> y;
        if(op == 1) {
            n = x, m = y;
        } else if(op == 2) {
            vector<int> b(a, a + n * m);
            swap(n, m);
            for(int i = 0; i < n; i ++)
                for(int j = 0; j < m; j ++) 
                    a[i * m + j] = b[j * n + i];
        } else {
            cout << a[x * m + y] << endl;
        }
    }
    return 0;
}