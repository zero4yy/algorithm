/*
给定一个由n*n个方格组成的地图,每个方格都有一个价值,每一步只能朝右或者朝下走,
从左上角到右下角走两次,一个方格内的价值只能获取一次,求可获取的最大总价值.
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 55;
#define endl '\n'
#define up 0
#define left 1

int dp[N][N];
bool path[N][N];
int v[N][N];   
// 回溯
void trace(int x, int y, int n) {
    if(x < 1 || y < 1) return;
    if(path[x][y] == up)
        trace(x - 1, y, n);
    else if(path[x][y] == left)
        trace(x, y - 1, n);

    if(x == 1 && y == 1) {
        cout << "A -> ";
        return;
    }
    else if(x == n && y == n)
        cout << "B" << endl << endl;
    else 
        cout << "(" << x << "," << y << ") -> ";

    v[x][y] = 0; //清空走过的格子
    return;
}
int solve(int n) {
    memset(dp, 0, sizeof(dp));
    memset(path, 0, sizeof(path));

    //第一列
    for(int i = 1; i <= n; i++) {
        path[i][1] = up;
        dp[i][1] = dp[i - 1][1] + v[i][1];
    }

    //第一行
    for(int j = 1; j <= n; j++) {
        path[1][j] = left;
        dp[1][j] = dp[1][j - 1] + v[1][j];
    }

    //动规实现
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
            path[i][j] = dp[i - 1][j] > dp[i][j - 1] ? up : left;
        }
    }

    trace(n, n, n);

    return dp[n][n];
}
int main() {
    freopen("testData/2.txt", "r", stdin);  
    int n; cin >> n;
    int x, y;
    while(cin >> x >> y >> v[x][y]) {
        if(!x) break;
    }
    int ans1 = solve(n);
    int ans2 = solve(n);
    cout << ans1 + ans2 ;
    return 0;
}