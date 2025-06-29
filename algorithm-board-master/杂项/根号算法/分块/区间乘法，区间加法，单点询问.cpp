#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[100005], pos[100005], l[333], r[333], add[333], mul[333], n, m, mod = 10007;
void change_add(ll left, ll right, ll c) {
    for (ll i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            (add[i] += c) %= mod;
        } else {
            for (ll j = l[i]; j <= r[i]; j++) {
                (d[j] *= mul[i]) %= mod;
                (d[j] += add[i]) %= mod;
            }
            mul[i] = 1;
            add[i] = 0;
            for (ll j = max(l[i], left); j <= min(r[i], right); j++) {
                (d[j] += c) %= mod;
            }
        }
    }
}
void change_mul(ll left, ll right, ll c) {
    for (ll i = pos[left]; i <= pos[right]; i++) {
        if (left <= l[i] && r[i] <= right) {
            (mul[i] *= c) %= mod;
            (add[i] *= c) %= mod;
        } else {
            for (ll j = l[i]; j <= r[i]; j++) {
                (d[j] *= mul[i]) %= mod;
                (d[j] += add[i]) %= mod;
            }
            mul[i] = 1;
            add[i] = 0;
            for (ll j = max(l[i], left); j <= min(r[i], right); j++) {
                (d[j] *= c) %= mod;
            }
        }
    }
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
        mul[i] = 1;
    }
    while (n--) {
        ll op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0) {
            change_add(l, r, c);
        } else if (op == 1) {
            change_mul(l, r, c);
        } else {
            cout << (d[r] * mul[pos[r]] + add[pos[r]]) % mod << endl;
        }
    }
    return 0;
}