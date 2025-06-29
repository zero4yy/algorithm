// https://loj.ac/p/133
// 内存消耗极大, 而且操作带两个log, 能不能过看评测机心情
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct SegTree2D {
    
    #define mid ((l + r) >> 1)

    int n, m, root, totx, toty, infx, infy;
    vector<int> rt, lsx, rsx, lsy, rsy, d;

    SegTree2D() {}
    SegTree2D(int n, int m) {    // 行、列要开的点数, 一般能开多大就开多大
        this->n = n;
        this->m = m;
        this->root = 0;
        this->totx = 0;
        this->toty = 0;
        this->infx = 1 << 12;   // x轴值域
        this->infy = 1 << 12;   // y轴值域
        rt = vector<int> (n + 5);
        lsx = vector<int> (n + 5);
        rsx = vector<int> (n + 5);
        lsy = vector<int> (m + 5);
        rsy = vector<int> (m + 5);
        d = vector<int> (m + 5);
    }

    void changeY(int& u, int l, int r, int y, int v) {    // 内修
        if (!u) u = ++toty; // 内树开点
        d[u] += v;
        if (l == r) return;
        if (y <= mid) changeY(lsy[u], l, mid, y, v);
        else changeY(rsy[u], mid + 1, r, y, v);
    }

    void changeX(int& u, int l, int r, int x, int y, int v) {    // 外修
        if (!u) u = ++totx; // 外树开点
        changeY(rt[u], 0, infy, y, v);
        if (l == r) return;
        if (x <= mid) changeX(lsx[u], l, mid, x, y, v);
        else changeX(rsx[u], mid + 1, r, x, y, v);
    }

    int queryY(int u, int l, int r, int y1, int y2) {   // 内查
        if (y1 <= l && r <= y2) return d[u];    // 内层覆盖即返回
        int res = 0;
        if (y1 <= mid) res += queryY(lsy[u], l, mid, y1, y2);
        if (y2 > mid) res += queryY(rsy[u], mid + 1, r, y1, y2);
        return res;
    }

    int queryX(int u, int l, int r, int x1, int y1, int x2, int y2) {   // 外查
        if (x1 <= l && r <= x2) return queryY(rt[u], 0, infy, y1, y2);   // 外层覆盖即入内
        int res = 0;
        if (x1 <= mid) res += queryX(lsx[u], l, mid, x1, y1, x2, y2);
        if (x2 > mid) res += queryX(rsx[u], mid + 1, r, x1, y1, x2, y2);
        return res;
    }

    void change(int x, int y, int v) {
        changeX(root, 0, infx, x, y, v);
    }

    int query(int x1, int y1, int x2, int y2) {
        return queryX(root, 0, infx, x1, y1, x2, y2);
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    SegTree2D S(1e5, 6e6);
    int op;
    while (cin >> op) {
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            S.change(x, y, k);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << S.query(x1, y1, x2, y2) << endl;
        }
    }
    return 0;
}
