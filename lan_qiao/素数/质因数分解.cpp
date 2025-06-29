//
// Created by Luzius on 2024/2/1.
//
//https://www.luogu.com.cn/problem/B3871
//#include<iostream>
//#include<map>
//#include<cmath>
//using namespace std;
//int prime[50005];
//bool vis[50005];
//map<int, int> mp;
//int E_sieve(int n){
//    for(int i = 2; i <= sqrt(n); i++)
//        if(!vis[i])
//            for(int j = i*i; j <= n; j += i)
//                vis[j] = true;
//    int k = 0;
//    for(int i = 2; i <= n; i++)
//        if(!vis[i])
//            prime[++k] = i;
//    return k;
//}
//int main(){
//    int N; cin >> N;
//    int k = E_sieve(50000);
//    for(int i = 1; i <= k; i++){
//        int p = prime[i];
//        while(N % p == 0){
//            N /= p;
//            mp[p]++;
//        }
//        if(p >= sqrt(N)){
//            mp[N]++;
//            break;
//        }
//    }
//
//    for(auto &y : mp){
//        cout << y.first;
//        if(y.second != 1) cout << "^" << y.second;
//        if(y != *mp.rbegin()) cout <<" * ";
//    }
//
//}
#include<iostream>
using namespace std;
typedef long long ll;
ll n, cnt;
int main(){
    cin >> n;
    for(ll i = 2; i * i <= n; i++){
        cnt = 0;
        if(n % i == 0){
            while (n % i == 0){
                n /= i;
                cnt++;
            }
            cout << i;
            if(cnt != 1) cout << '^' << cnt;
            if(n > 1) cout << " * ";
        }
    }
    if(n > 1) cout << n;
}