#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[100005], pos[100005], l[333], r[333], add[333], sum[333], n, m;
void change(ll left, ll right, ll c) {
    for (ll i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            add[i] += c;
            sum[i] += c * (r[i] - l[i] + 1);
        } else {
            for (ll j = max(l[i], left); j <= min(r[i], right); j++) {
                d[j] += c;
                sum[i] += c;
            }
        }
    }
}
ll ask(ll left, ll right) {
    ll res = 0;
    for (ll i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            res += sum[i];
        } else {
            for (ll j = max(l[i], left); j <= min(r[i], right); j++) {
                res += d[j] + add[i];
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
        ll t = 0;
        for (ll j = l[i]; j <= r[i]; j++) {
            pos[j] = i;
            t += d[j];
        }
        sum[i] = t;
    }
    while (n--) {
        ll op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0) {
            change(l, r, c);
        } else {
            cout << (ask(l, r) % (c + 1)) << endl;
        }
    }
    return 0;
}