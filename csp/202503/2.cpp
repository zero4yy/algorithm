#include <iostream>

using namespace std;

const int N = 1e4 + 5;
int n, m; // n:容量  m:物品数量
int a[105];
int f[N];

// 完全背包问题
void work() {
    for(int i = 1; i <= m; i ++) {
        for(int j = i; j <= n; j ++) {
            f[j] = max(f[j], f[j - i] + a[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) cin >> a[i];

    work();
    cout << f[n];
    return 0;
}