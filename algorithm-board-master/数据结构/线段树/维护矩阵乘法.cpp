// https://www.luogu.com.cn/problem/CF718C
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

vector<vector<int>> e(2, vector<int> (2));  // 单位矩阵
vector<vector<int>> mat(2, vector<int> (2));// 转移矩阵
vector<vector<int>> dp = {{1}, {0}};        // 初始值


vector<vector<int>> mat_add(const vector<vector<int>>& a, const vector<vector<int>>& b) { // 给定两个矩阵a和b, 矩阵大小应相同, 求a + b
    int n = a.size(), m = a[0].size();
    int mod = 1e9 + 7;
    vector<vector<int>> c(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = (a[i][j] + b[i][j]) % mod;
        }
    }
    return c;
}

vector<vector<int>> mat_mul(const vector<vector<int>>& a, const vector<vector<int>>& b) { // 给定n x p和p x m的两个矩阵a和b, 求a x b
    int n = a.size(), p = a[0].size(), m = b[0].size();
    int mod = 1e9 + 7;
    vector<vector<int>> c(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                c[i][j] = (((a[i][k] * b[k][j]) % mod + c[i][j]) % mod + mod) % mod;
            }
        }
    }
    return c;
}

vector<vector<int>> mat_pow(vector<vector<int>> a, int b) {    // 求矩阵a的b次方
    int n = a.size();
    vector<vector<int>> res(n, vector<int> (n));
    for (int i = 0; i < n; i++) {   // 把res初始化为n阶单位矩阵
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    } 
    return res;
}

template<class Info, class Tag>
struct LazySegmentTree {

    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegmentTree() {}

    LazySegmentTree(int n) {
        init(vector<Info>(n, Info()));
    }

    LazySegmentTree(const vector<Info> &_info) {
        init(_info);
    }

    void init(const vector<Info> &_info) {
        n = _info.size();
        info.assign(4 * n, Info());
        tag.assign(4 * n, Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r) {
                info[p] = _info[l];
                return;
            }

            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 0, n - 1);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l > y || r < x) {
            return;
        }

        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }

        push(p);
        int m = (l + r) / 2;
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n - 1, l, r, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l > y || r < x) {
            return Info();
        }

        if (l >= x && r <= y) {
            return info[p];
        }

        push(p);
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }
};

struct Tag {
    vector<vector<int>> mat;
    Tag() {
        this->mat = e;
    }
    Tag(const vector<vector<int>>& mat) {
        this->mat = mat;
    }
    void apply(const Tag &t) {
        mat = mat_mul(mat, t.mat);
    }
};

struct Info {
    vector<vector<int>> mat;
    Info() {
        this->mat = vector<vector<int>> (2, vector<int> (2));
    }
    Info(const vector<vector<int>>& mat) {
        this->mat = mat;
    }
    void apply(const Tag &t) {
        mat = mat_mul(t.mat, mat);
    }
};

Info operator+(const Info &a, const Info &b) {
    return Info(mat_add(a.mat, b.mat));
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    e[0][0] = 1;
    e[1][1] = 1;
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    int n, m;
    cin >> n >> m;
    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        a[i].mat = mat_mul(mat_pow(mat, p - 1), dp);
    }
    LazySegmentTree<Info, Tag> seg(a);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--; r--;
            seg.rangeApply(l, r, {mat_pow(mat, x)});
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << seg.rangeQuery(l, r).mat[0][0] << endl;
        }
    }
    return 0;
}