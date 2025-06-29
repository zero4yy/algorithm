#include <bits/stdc++.h>
using namespace std;
int d[100005], pos[100005], l[333], r[333], flag[333], sum[333], n, m;
void change(int left, int right) {
    for (int i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            if (flag[i]) {
                continue;
            } else {
                bool fa = true;
                for (int j = l[i]; j <= r[i]; j++) {
                    int diff = d[j] - (int)sqrt(d[j]);
                    d[j] -= diff;
                    sum[i] -= diff;
                    if (d[j] > 1) fa = false;
                }
                if (fa) flag[i] = 1;
            }
        } else {
            for (int j = max(l[i], left); j <= min(r[i], right); j++) {
                int diff = d[j] - (int)sqrt(d[j]);
                d[j] -= diff;
                sum[i] -= diff;
            }
        }
    }
}
int ask(int left, int right) {
    int res = 0;
    for (int i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            res += sum[i];
        } else {
            for (int j = max(l[i], left); j <= min(r[i], right); j++) {
                res += d[j];
            }
        }
    }
    return res;
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
        int t = 0;
        for (int j = l[i]; j <= r[i]; j++) {
            pos[j] = i;
            t += d[j];
        }
        sum[i] = t;
    }
    while (n--) {
        int op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0) {
            change(l, r);
        } else {
            cout << ask(l, r) << endl;
        }
    }
    return 0;
}