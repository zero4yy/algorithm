#include <bits/stdc++.h>
using namespace std;
int d[100005], pos[100005], l[2333], r[2333], f[2333][2333], n, m;
unordered_map<int, vector<int>> c;
template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
int get(int left, int right, int v) {
    return upper_bound(c[v].begin(), c[v].end(), right) - lower_bound(c[v].begin(), c[v].end(), left);
}
int ask(int left, int right) {
    int le = (left == l[pos[left]] ? pos[left] : pos[left] + 1);
    int ri = (right == r[pos[right]] ? pos[right] : pos[right] - 1);
    int res = f[le][ri], max_cnt = get(left, right, res);
    for (int i = left; i <= r[pos[left]]; i++) {
        int cnt = get(left, right, d[i]);
        if (cnt > max_cnt || (cnt == max_cnt && res > d[i])) {
            res = d[i];
            max_cnt = cnt;
        }
    }
    for (int i = l[pos[right]]; i <= right; i++) {
        int cnt = get(left, right, d[i]);
        if (cnt > max_cnt || (cnt == max_cnt && res > d[i])) {
            res = d[i];
            max_cnt = cnt;
        }
    }
    return res;
}
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(d[i]);
        c[d[i]].push_back(i);
    }
    int block_len = 80;
    int m = (n + block_len - 1) / block_len;
    for (int i = 1; i <= m; i++) {
        l[i] = block_len * (i - 1) + 1;
        r[i] = block_len * i;
    }
    r[m] = n;
    for (int i = 1; i <= m; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            pos[j] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        unordered_map<int, int> cn;
        int num, max_cnt = 0;
        for (int j = i; j <= m; j++) {
            for (int k = l[j]; k <= r[j]; k++) {
                cn[d[k]]++;
                if (cn[d[k]] > max_cnt || (cn[d[k]] == max_cnt && num > d[k])) {
                    num = d[k];
                    max_cnt = cn[d[k]];
                }
            }
            f[i][j] = num;
        }
    }
    while (n--) {
        int l, r;
        read(l), read(r);
        print(ask(l, r));
        puts("");
    }
    return 0;
}