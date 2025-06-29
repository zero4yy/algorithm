// https://www.acwing.com/problem/content/832/
// 输出每个数左边第一个比它小的数
#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        while(tt && stk[tt] >= x) tt --; // 栈顶元素大于 x，永远不会用到，弹出栈
        // 最终得到的一个严格单调上升的序列
        if(tt) cout << stk[tt] << ' '; // 弹出栈顶元素
        else cout << -1 << ' '; 

        stk[++ tt] = x;
    }

    return 0;
}
/*
5
3 4 2 7 5
*/