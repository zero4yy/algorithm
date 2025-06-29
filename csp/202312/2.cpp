#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int q;
ll n, k, cnt, ans;
ll fpow(ll a, ll b){//快速幂精简版 a^11 = a^8 * a^2 * a^1
    ll ans = 1;
    while(b){
        if(b&1)ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main() {
    cin >> q;
    while(q--) {
        vector<pair<ll, ll> > vt;
        cin >> n >> k;
        //进行质因数分解
        for(int i = 2; i * i <= n; i++) {
            cnt = 0;
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                } 
                vt.push_back(make_pair(i, cnt));
            }
        }
        if(n > 1) vt.push_back(make_pair(n, 1));
        
        ans = 1;
        for(int i = 0; i < vt.size(); i++) {  
            if(vt[i].second >= k) {
                ans *= fpow(vt[i].first, vt[i].second);
            }
        }

        cout << ans << endl;
    }
    return 0;
}