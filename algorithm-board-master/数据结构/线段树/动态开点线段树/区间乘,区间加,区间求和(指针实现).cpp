// https://www.luogu.com.cn/problem/P3373
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct SegTree {

    int value, mul, add, mod;
    SegTree* left;
    SegTree* right;

    SegTree() { 
        this->value = 0; 
        this->mul = 1;
        this->add = 0;
        this->mod = 1e9 + 7;
        this->left = NULL;
        this->right = NULL;
    }

    void push_down(SegTree* root, int l, int r, int m) {
        if (root->mul != 1 || root->add != 0) {
            if (root->left == NULL) root->left = new SegTree();
            if (root->right == NULL) root->right = new SegTree();
            root->left->value = (root->left->value * root->mul % mod + root->add * (m - l + 1) % mod) % mod;
            root->right->value = (root->right->value * root->mul % mod + root->add * (r - m) % mod) % mod;
            root->left->mul = root->left->mul * root->mul % mod;
            root->right->mul = root->right->mul * root->mul % mod;
            root->left->add = (root->left->add * root->mul % mod + root->add) % mod;
            root->right->add = (root->right->add * root->mul % mod + root->add) % mod;
            root->mul = 1;
            root->add = 0;
        }
    }

    void change(SegTree* root, int l, int r, int ql, int qr, int mul, int add) {
        if (ql <= l && r <= qr) {
            root->value = (root->value * mul % mod + (r - l + 1) * add % mod) % mod;
            root->mul = root->mul * mul % mod;
            root->add = (root->add * mul % mod + add) % mod;
            return;
        }
        int m = l + r >> 1;
        push_down(root, l, r, m);
        if (ql <= m) {
            if (root->left == NULL) root->left = new SegTree();
            change(root->left, l, m, ql, qr, mul, add);
        }
        if (m < qr) {
            if (root->right == NULL) root->right = new SegTree();
            change(root->right, m + 1, r, ql, qr, mul, add);
        }
        root->value = 0;
        if (root->left != NULL) root->value = (root->value + root->left->value) % mod;
        if (root->right != NULL) root->value = (root->value + root->right->value) % mod;
    }

    int query(SegTree* root, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return root->value;
        }
        int m = l + r >> 1;
        push_down(root, l, r, m);
        int res = 0;
        if (ql <= m) {
            if (root->left != NULL) {
                res = (res + query(root->left, l, m, ql, qr)) % mod;
            }
        }
        if (m < qr) {
            if (root->right != NULL) {
                res = (res + query(root->right, m + 1, r, ql, qr)) % mod;
            }
        }
        return res;
    }

    void change(int ql, int qr, int mul, int add) { // 对于所有i∈[ql,qr], 将a[i]变成a[i]*mul+add
        change(this, 0, 1e6, ql, qr, mul, add);
    }

    int query(int ql, int qr) { // 询问区间[ql,qr]的和
        return query(this, 0, 1e6, ql, qr);
    }

};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, q;
    cin >> n >> q;
    SegTree S;
    cin >> S.mod;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        S.change(i, i, 1, a);
    }
    while (q--) {
        int op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            S.change(l, r, x, 0);
        } else if (op == 2) {
            cin >> l >> r >> x;
            S.change(l, r, 1, x);
        } else {
            cin >> l >> r;
            cout << S.query(l, r) << endl;
        }
    }
    return 0;
}
