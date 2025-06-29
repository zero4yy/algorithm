#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[100005], pos[100005], l[333], r[333], flag[333], n, m;
ll ask(ll left, ll right, ll c) {
    ll res = 0;
    for (ll i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            if (flag[i] != 1e18) {
                if (flag[i] == c) {
                    res += r[i] - l[i] + 1;
                }
            } else {
                for (ll j = l[i]; j <= r[i]; j++) {
                    if (d[j] == c) {
                        res++;
                    }
                }
            }
            flag[i] = c;
        } else {
            if (flag[i] != 1e18) {
                for (ll j = l[i]; j <= r[i]; j++) {
                    d[j] = flag[i];
                }
                flag[i] = 1e18;
            }
            for (ll j = max(l[i], left); j <= min(r[i], right); j++) {
                if (d[j] == c) {
                    res++;
                }
                d[j] = c;
            }
        }
    }
    return res;
}
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> d[i];
    }
    m = sqrt(n);
    for (ll i = 1; i <= m; i++) {
        l[i] = m * (i - 1) + 1;
        r[i] = m * i;
    }
    r[m] = n;
    for (ll i = 1; i <= m; i++) {
        for (ll j = l[i]; j <= r[i]; j++) {
            pos[j] = i;
        }
        flag[i] = 1e18;
    }
    while (n--) {
        ll l, r, c;
        cin >> l >> r >> c;
        cout << ask(l, r, c) << endl;
    }
    return 0;
}