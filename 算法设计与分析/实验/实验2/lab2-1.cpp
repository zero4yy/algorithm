//0-1背包
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N = 10005;
ll dp[N][N], v[N], w[N];
ll n, c;
void solve() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= c; ++j) {
            if(j < w[i]) 
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = max(
                    dp[i - 1][j - w[i]] + v[i],
                    dp[i-1][j]
                );
        }
    }
}
int main() {
    ifstream ifs("testData/mid_1.txt");
    ofstream ofs("results/test3000.txt");
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ifs >> n >> c;
    for(int i = 1; i <= n; ++i) ifs >> w[i] >> v[i];
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    solve();
    // 结束计时
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    ofs << dp[n][c] << endl;
    ofs << "time: " << duration.count() << " ms" << endl;
    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= c; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}