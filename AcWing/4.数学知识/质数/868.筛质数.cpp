#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int n, prime[N], cnt;
bool st[N]; // 标记是否是素数

void get_primes_imporve() {
    for(int i = 2; i <= sqrt(n); i ++) {
        if(st[i]) continue;
        for(int j = i * i; j <= n; j += i)
            st[j] = true;
    }

    for(int i = 2; i <= n; i ++) {
        if(!st[i]) prime[cnt++] = i;
    }
}

void get_primes() {
    for(int i = 2; i <= n; i ++) {
        if(st[i]) continue;
        prime[cnt ++] = i;
        for(int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

int main() {
    cin >> n;
    get_primes();
    cout << cnt;
    return 0;
}