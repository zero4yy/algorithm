// https://www.luogu.com.cn/problem/CF566D
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

// 给你一个数列，让你支持三种操作：

// 1. 将两个元素合并为同类；

// 2. 将一段元素合并为同类；

// 3. 查询两个元素是否为同一类。

struct dsu {
    
    vector<int> fa, siz, nxt;

    dsu() {}
    dsu(int n) {
        fa.resize(n + 5);
        siz.resize(n + 5, 1);
        nxt.resize(n + 5);
        for (int i = 0; i < n + 5; i++) {
            fa[i] = i;
            nxt[i] = i + 1;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge_point(int a, int b) {    // 合并 x 和 y
        a = find(a);
        b = find(b);
        if (a == b) return false;
        siz[a] += siz[b];
        fa[b] = a;
        return true;
    }

    void merge_range(int l, int r) {    // 合并[l, r]内的所有元素, 均摊复杂度O(1)
        int to;
        for (int i = l + 1; i <= r; i = to) {
            merge_point(i - 1, i);
            to = nxt[i];
            nxt[i] = nxt[r];
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return siz[find(x)];
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, q;
    cin >> n >> q;
    dsu D(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            D.merge_point(x, y);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            D.merge_range(l, r);
        } else {
            int x, y;
            cin >> x >> y;
            cout << (D.same(x, y) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
