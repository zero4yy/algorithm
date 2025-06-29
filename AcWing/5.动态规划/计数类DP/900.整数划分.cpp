//https://www.acwing.com/problem/content/902/
#include <iostream>

using namespace std;

const int N = 1010;
const int mod = 1e9 + 7;
int f[N];
int n;
/*
1.完全背包问题

                         |---集合：从1-i选, 体积恰好为 j 的数量
     |---状态表示f(i,j)---|
     |                   |---属性：数量
     |
DP---|
     |
     |     
     |---状态计算     ---| 
                        |  
                        |  
f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j-2*i] + ... + f[i-1][j-s*i]
f[i][j-i] =           f[i-1][j-i] + f[i-1][j-2*i] + ... + f[i-1][j-s*i]

-> f[i][j] = f[i - 1][j] + f[i][j-i];

-> 优化 f[j] = f[j] + f[j - i];

5

5
4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

*/

// 完全背包
void solve1() {
    f[0] = 1; // 体积为 0 只有 1 种方案
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j ++) {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    cout << f[n] << endl;
}
int main() {
    cin >> n;

    return 0;
}