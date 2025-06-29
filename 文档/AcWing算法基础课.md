# 第一讲 基础算法

## 双指针

### AcWing 799. 最长连续不重复子序列

```c++
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N]; // s 表示某一个数出现的次数
int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    int res = 0;
    for(int i = 0, j = 0; i < n; i ++) {
        s[a[i]] ++;
        while(s[a[i]] > 1) {
            s[a[j]] --;
            j ++;
        }

        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
```

### AcWing 800. 数组元素的目标和

```c++
#include <iostream>

using namespace std;

const int N = 100010;

int n, m, x;
int A[N], B[N];
int main() {
    cin >> n >> m >> x;
    for(int i = 0; i < n; i ++) cin >> A[i];
    for(int i = 0; i < m; i ++) cin >> B[i];


    int i = 0, j = m - 1;
    while(i < n && j >= 0) {
        if(A[i] + B[j] == x) {
            cout << i << ' ' << j << endl;
            break;
        }
        
        else if(A[i] + B[j] > x) j --;
        else i++;
    }
    return 0;
}
```



# 第二讲 数据结构

## 哈希表

### AcWing 840. 模拟散列表

拉链法（<font color=red>存储和图相似</font>）：

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;
int n, x;
string op;
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if(e[i] == x)
            return true;

    return false;
    
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    while (n --)
    {   
        cin >> op >> x;
        if(op == "I") insert(x);
        else {
            if(find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } 
    }
    return 0;
}
```

开放寻址法

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003; // 2~3倍
const int null = 0x3f3f3f3f;


int h[N];
int n, x;
string op;

// 如果第k个位置为空
int find(int x) {
    int k = (x % N + N) % N;

    while(h[k] != null && h[k] != x) {
        k ++;
        if(k == N) k = 0;
    }

    return k;
    
}

int main() {
    memset(h, 0x3f, sizeof h);
    cin >> n;
    while (n --)
    {   
        cin >> op >> x;
        if(op == "I") h[find(x)] = x;
        else {
            if(h[find(x)] == null) cout << "No" << endl;
            else cout << "Yes" << endl;
        } 
    }
    return 0;
}
```

### AcWing 841. 字符串哈希

# 第三讲 搜索与图论

## 树与图的深度优先遍历

### AcWing 846. 树的重心

```c++
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

```

