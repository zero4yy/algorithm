#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;
int n, m;
int v[N], w[N];
int F[N][N];
int f[N];
/*
每个物品无限次选择


                         |---集合：所有只从前 i 个物品中选, 总体积不超过 j 的方案集合
     |---状态表示f(i,j)---|
     |                   |---属性：max
     |
DP---|
     |
     |                  |  对第 i 个物品的选择进行划分, 可以选 k 次
     |---状态计算     ---|  f(i,j) = max(f(i - 1, j), f(i-1, j - v[i]) + w[i], f(i - 1, j - 2*v[i]) + 2*w[i] ...);
                        |  神来之笔： f(i,j-v[i]) = max(f(i - 1, j - v[i]), f(i - 1, j - 2*v[i]) + w[i], f(i - 1, j - 3*v[i]) + 2*w[i] ...)
                        |  易得：f(i,j) = max(f(i-1, j), f(i, j-v[i]) + w[i]);

 
01背包:   f[i][j] = max(f[i - 1][j], f[i - 1][j - v]+ w);
完全背包: f[i][j] = max(f[i - 1][j], f[i][j - v] + w); 
*/

void erwei() {
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            F[i][j] = F[i - 1][j];
            if(j >= v[i]) F[i][j] = max(F[i][j], F[i][j - v[i]] + w[i]);
        }
    }
    cout << F[n][m] << endl;
}

void yiwei() {
    // 遍历物品
    // 遍历体积
    for(int i = 1; i <= n; i ++) {
        for(int j = v[i]; j <= m; j ++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    erwei();
    //yiwei();
    return 0;
}