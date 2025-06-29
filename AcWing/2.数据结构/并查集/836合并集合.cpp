#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

// 返回 x 的祖宗节点 + 路径压缩
int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) p[i] = i;
    string op;
    int a, b;
    while(1) {
        cin >> op >> a >> b;
        cout << find(a) << ' ' << find(b) << endl;
        if(op == "M") p[find(a)] = find(b);
        else {
            if(find(a) == find(b)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}