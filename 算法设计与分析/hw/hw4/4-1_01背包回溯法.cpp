#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1005;
int n, c;
int w[N], v[N];
int x[N]; // 标记是否选择物品i 
int ans = 0;
// 定义界限函数
bool bound(int dep, int sum_weight) {
    return sum_weight <= c;
}
void backtrack(int dep, int sum_weight, int sum_value) {
    if(sum_weight > c) return; // 剪枝
    if(dep >= n) { // 深度超过n，终止
        if(sum_value > ans) ans = sum_value;
    } else {
        // for(int i = 0; i <= 1; ++i) {
        //     x[dep] = i;
        //     // 判断是否满足界限条件
        //     if(bound(dep)) { // 满足界限，向下递归
        //         backtrack(dep + 1);
        //     }
        // }
        // 满足界限条件，向下递归
        if(bound(dep, sum_weight)) {
            // 选择物品
            backtrack(dep + 1, sum_weight + w[dep], sum_value + v[dep]);
            // 不选择物品
            backtrack(dep + 1, sum_weight, sum_value);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c;
    
    cin >> n;

    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    backtrack(0, 0, 0);
    cout << ans;
    return 0;
}