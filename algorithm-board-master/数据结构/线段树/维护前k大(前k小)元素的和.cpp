// https://www.luogu.com.cn/problem/AT_abc287_g
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct SegTree {

    int value;
    SegTree* left;
    SegTree* right;

    SegTree() { 
        this->value = 0; 
        this->left = NULL;
        this->right = NULL;
    }

    void change(SegTree* root, int l, int r, int pos, int value) {
        if (l == r) {
            root->value += value;
            return;
        }
        int m = l + r >> 1;
        if (pos <= m) {
            if (root->left == NULL) root->left = new SegTree();
            change(root->left, l, m, pos, value);
        }
        if (m < pos) {
            if (root->right == NULL) root->right = new SegTree();
            change(root->right, m + 1, r, pos, value);
        }
        root->value = 0;
        if (root->left != NULL) root->value += root->left->value;
        if (root->right != NULL) root->value += root->right->value;
    }

    int query(SegTree* root, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return root->value;
        }
        int m = l + r >> 1;
        int res = 0;
        if (ql <= m) {
            if (root->left != NULL) {
                res += query(root->left, l, m, ql, qr);
            }
        }
        if (m < qr) {
            if (root->right != NULL) {
                res += query(root->right, m + 1, r, ql, qr);
            }
        }
        return res;
    }
    
    int get_pos(SegTree* root, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int m = l + r >> 1;
        if (root->left != NULL && root->left->value >= k) {
            return get_pos(root->left, l, m, k);
        } else {
            return get_pos(root->right, m + 1, r, k - (root->left == NULL ? 0 : root->left->value));
        }
    }

    void change(int pos, int value) {
        change(this, 0, 1e9, pos, value);
    }

    int query(int ql, int qr) { // 求值域[ql,qr]元素的和
        return query(this, 0, 1e9, ql, qr);
    }
    
    int get_pos(int k) {  // 求第k小元素位置 (如果想求第k大元素位置, 可以求第n-k小)
        return get_pos(this, 0, 1e9, k);
    }

};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    SegTree S1, S2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        S1.change(a[i], a[i] * b[i]);
        S2.change(a[i], b[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            S1.change(a[x], -a[x] * b[x]);
            S2.change(a[x], -b[x]);
            a[x] = y;
            S1.change(a[x], a[x] * b[x]);
            S2.change(a[x], b[x]);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            S1.change(a[x], -a[x] * b[x]);
            S2.change(a[x], -b[x]);
            b[x] = y;
            S1.change(a[x], a[x] * b[x]);
            S2.change(a[x], b[x]);
        } else {
            int x;
            cin >> x;
            int cnt = S2.query(0, 1e9);
            if (cnt < x) {
                cout << -1 << endl;
            } else {
                int p = S2.get_pos(cnt - x);
                int cnt1 = S2.query(p, 1e9);
                cout << S1.query(p, 1e9) - p * (cnt1 - x) << endl;
            }
        }
    }
    return 0;
}
