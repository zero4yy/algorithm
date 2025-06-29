// https://www.luogu.com.cn/problem/B3644
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct Top_sort {
    
    int n;
    vector<vector<int>> adj;
    vector<int> cnt;

    Top_sort() {}
    Top_sort(int n) {
        this->n = n;
        adj = vector<vector<int>> (n + 1);
        cnt = vector<int> (n + 1);
    }

    void add(int a, int b) {    // 添加一条从a指向b的有向边
        adj[a].push_back(b);
        cnt[b] += 1;
    }

    vector<int> get_topsort() { // 获取任意的一条拓扑序列。若无法生成，则返回空数组
        vector<int> res;
        deque<int> q;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) q.push_back(i);
        }
        while (q.size()) {
            int now = q.front();
            q.pop_front();
            res.push_back(now);
            for (int nxt : adj[now]) {
                cnt[nxt]--;
                if (cnt[nxt] == 0) q.push_back(nxt);
            }
        }
        if (res.size() != n) return {};
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    Top_sort T(n);
    for (int i = 1; i <= n; i++) {
        int a;
        while (cin >> a && a != 0) {
            T.add(i, a);
        }
    }
    vector<int> res = T.get_topsort();
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
