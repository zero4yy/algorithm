#include <bits/stdc++.h>
using namespace std;
int d[100005], pos[100005], l[333], r[333], add[333], n, m;
void change(int left, int right, int c) {
    for (int i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            add[i] += c;
        } else {
            for (int j = max(l[i], left); j <= min(r[i], right); j++) {
                d[j] += c;
            }
        }
    }
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
            pos[j] = i;
        }
    }
    while (n--) {
        int op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0) {
            change(l, r, c);
        } else {
            cout << d[r] + add[pos[r]] << endl;
        }
    }
    return 0;
}