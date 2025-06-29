// https://loj.ac/p/103
#include <bits/stdc++.h>

using namespace std;

struct String_hash {

    int mod = 1e9 + 7;
    static int base;
    vector<int> pre, suf, p;

    String_hash() {}
    String_hash(string s) {
        int n = s.size();
        pre = vector<int> (n + 5);
        suf = vector<int> (n + 5);
        p = vector<int> (n + 5);
        p[0] = 1;

        if (base == 0) {
            mt19937 rng = mt19937(static_cast<unsigned int>(time(0)));
            uniform_int_distribution<int> dist(100, 233);
            base = dist(rng);
        }

        for (int i = 0; i < n; i++) {
            p[i + 1] = 1LL * p[i] * base % mod;
            pre[i + 1] = (1LL * pre[i] * base % mod + s[i] - 'a' + 1) % mod;
        }

        for (int i = n - 1; i >= 0; i--) {
            suf[i + 1] = (1LL * suf[i + 2] * base % mod + s[i] - 'a' + 1) % mod;
        }
    }

    int get_hash(int l, int r) {
        l++, r++;
        return ((pre[r] - 1LL * pre[l - 1] * p[r - l + 1] % mod) % mod + mod) % mod;
    }

    int get_hash_rev(int l, int r) {
        l++, r++;
        return ((suf[l] - 1LL * suf[r + 1] * p[r - l + 1] % mod) % mod + mod) % mod;
    }
};

int String_hash::base = 0;

int main() {
    string a, b;
    cin >> a >> b;
    String_hash A(a), B(b);
    int n = a.size(), m = b.size(), res = 0;

    for (int i = 0; i + m - 1 < n; i++) {
        if (A.get_hash(i, i + m - 1) == B.get_hash(0, m - 1))
            res++;
    }

    cout << res << endl;
    return 0;
}