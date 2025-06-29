// https://www.acwing.com/problem/content/848/
// bfs模板
// void dfs (int u) {
//     st[u] = true;
//     for(int i = h[u]; i != -1; i = ne[i]) {
//         int j = e[i];
//         if(!st[j]) {
//             dfs(j);
//         }
//     }
// }
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 100010, M = 2 * N;

int h[N]; //邻接表存储树，有n个节点，所以需要n个链表头节点
int e[M]; //e[i] 表示节点i的值
int ne[M]; //ne[i] 表示节点i的next指针是多少
int idx; //可以理解为地址空间
int n;
int ans = N;

bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 返回以u为根的子树中节点的个数，包括u点
int dfs(int u) {
    int res = 0;
    st[u] = true;
    int sum = 1; //sum从1开始，根节点

    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s; //以j为根的树的节点个数
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);

    cout << ans << endl;

    return 0;
}
