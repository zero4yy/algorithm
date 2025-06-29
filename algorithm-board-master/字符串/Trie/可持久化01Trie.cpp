// https://loj.ac/p/6850
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct Trie01 {

    int limit = 23;
    int idx = 0, cnt = 0;
    vector<int> rt, siz;
    vector<vector<int>> ch;

    Trie01() {}
    Trie01(int n) {
        rt = vector<int> (n + 1);
        ch = vector<vector<int>> (limit * n, vector<int> (2));
        siz = vector<int> (limit * n);
    }

    void insert(int v) {
        rt[++idx] = ++cnt;
        int x = rt[idx - 1];
        int y = rt[idx];
        for (int i = limit; i >= 0; i--) {
            int j = v >> i & 1;
            ch[y][!j] = ch[x][!j];
            ch[y][j] = ++cnt;
            x = ch[x][j];
            y = ch[y][j];
            siz[y] = siz[x] + 1;
        }
    }

    int query(int l, int r, int v) {    // 区间[l, r]内一个元素与v异或的最大值
        int res = 0;
        for (int i = limit; i >= 0; i--) {
            int j = v >> i & 1;
            if (siz[ch[r][!j]] > siz[ch[l][!j]]) {
                l = ch[l][!j];
                r = ch[r][!j];
                res += 1 << i;
            } else {
                l = ch[l][j];
                r = ch[r][j];
            }
        }
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    int s = 0;
    Trie01 T(n + m);
    T.insert(0);    // 下标变成了从2开始, 如果需要从1开始的下标, 则不需要哨兵
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s ^= x;
        T.insert(s);
    }
    while (m--) {
        string op;
        cin >> op;
        if (op == "A") {
            int x;
            cin >> x;
            s ^= x;
            T.insert(s);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            cout << T.query(T.rt[l - 1], T.rt[r], s ^ x) << endl;
        }
    }
    return 0;
}
