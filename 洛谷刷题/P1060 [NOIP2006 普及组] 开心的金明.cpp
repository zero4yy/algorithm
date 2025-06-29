#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5, M = 30;
typedef long long ll;
ll v[M], val[M], dp[N];
int n, m, w;
// 01 ±³°üÎÊÌâ 
int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) {
		cin >> v[i] >> w;
		val[i] = v[i] * w;
	}
	for(int i = 1; i <=m; i++) {
		for(int j = n; j >= v[i]; j--) {
			dp[j] = max(dp[j], dp[j - v[i]] + val[i]); 
		}
	}
	cout << dp[n];
}
