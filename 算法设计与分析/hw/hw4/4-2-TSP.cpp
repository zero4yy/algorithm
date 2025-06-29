#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N = 1005;
int n;
int bestc;
int cost[N][N];
int vis[N];
int cal_bestc() {
    int maxSum = 0;
    for(int i = 0; i < n; i++) {
        maxSum += *max_element(cost[i], cost[i] + n);
    }
    return maxSum + 1;
}
void dfs(int s, int curr, int cnt, int currCost) {
    // 如果已经遍历完所有城市
    if(cnt > n) {
        currCost += cost[curr][s];
        bestc = min(bestc, currCost);
        return;
    } 
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && currCost + cost[curr][i] < bestc) { // 剪枝
            vis[i] = 1;
            dfs(s, i, cnt + 1, currCost + cost[curr][i]);
            vis[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }
    bestc = cal_bestc(); // 初始上界

    dfs(1, 1, 1, 0); // 从起点开始

    cout << bestc;
    return 0;

}