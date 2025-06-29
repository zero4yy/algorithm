#include <bits/stdc++.h>
using namespace std;
int d[100005], l[333], r[333], n, m;
vector<vector<int>> v(333);
void rebuild(int pos) {
    vector<int> t;
    int n = v[pos].size();
    for (int i = 0; i < n / 2; i++) {
        t.push_back(v[pos].back());
        v[pos].pop_back();
    }
    reverse(t.begin(), t.end());
    v.insert(v.begin() + pos + 1, t);
}
void change(int pos, int c) {
    int i = 1;
    while (pos > v[i].size()) {
        pos -= v[i].size();
        i++;
    }
    v[i].insert(v[i].begin() + pos - 1, c);
    if (v[i].size() > 10 * m) {
        rebuild(i);
    }
}
int ask(int pos) {
    int i = 1;
    while (pos > v[i].size()) {
        pos -= v[i].size();
        i++;
    }
    return v[i][pos - 1];
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    m = sqrt(n);
    for (int i = 1; i <= m; i++) {
        l[i] = m * (i - 1) + 1;
        r[i] = m * i;
    }
    r[m] = n;
    for (int i = 1; i <= m; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            v[i].push_back(d[j]);
        }
    }
    while (n--) {
        int op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0) {
            change(l, r);
        } else {
            cout << ask(r) << endl;
        }
    }
    return 0;
}