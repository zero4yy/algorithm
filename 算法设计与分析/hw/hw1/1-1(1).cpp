#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
const int N = 13;
using namespace std;
ll n, dp[N], weight[N], ans[N];
int a[N];
void solve(ll n) {
    ll _n = n;
    int len = 0;
    while(n) a[++len] = n % 10, n /= 10;
    for(int i = len; i >= 1; i--) {
        //前i-1位的贡献
        for(int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i]; 
        //第i位的贡献
        for(int j = 0; j < a[i]; j++) ans[j] += weight[i - 1];  
        _n -= weight[i - 1] * a[i];
        ans[a[i]] += _n + 1;
        ans[0] -= weight[i - 1];
    }

}
int main() {
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    weight[0] = 1ll;
    for(int i = 1; i <= 13; ++i) {
        dp[i] = dp[i - 1] * 10 + weight[i - 1];
        weight[i] = weight[i - 1] * 10;
    }
    solve(n);
    for(int i = 0; i < 10; i++) ofs << ans[i] << endl;
    ifs.close();
    ofs.close();
    return 0;
}
