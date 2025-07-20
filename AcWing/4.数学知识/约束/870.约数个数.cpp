#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 105, mod = 1e9 + 7;
int n, x;
unordered_map<int, int> prime;

ll ans = 1;

void work() {
    // 对x分解
    for(int i = 2; i <= x/i; i ++) {
        while(x % i == 0) {
            prime[i] ++;
            x /= i;
        }
    }
    if(x > 1) prime[x] ++;
}

int main() {
    cin >> n;
    
    while(n --) {
        cin >> x;
        work();
    }
    
    for(auto p : prime) ans = ans * (p.second + 1) % mod;
    
    cout << ans;
}