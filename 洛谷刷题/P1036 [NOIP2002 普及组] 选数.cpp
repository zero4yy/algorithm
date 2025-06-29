#include<bits/stdc++.h>
using namespace std;
int n, k;
int  x[25];
bool isprime(int x){
	if(x < 2) return false;
	for(int i = 2; i <= x/i; i++) {
		if(x % i == 0) return false;
	}
	return true;
}
int dfs(int dep, int cnt, int sum) {
	if(cnt >= k) return (int)isprime(sum);
	if(dep > n) return 0;
	int res = 0;
	res += dfs(dep + 1, cnt, sum);
	res += dfs(dep + 1, cnt + 1, sum + x[dep]);
	return res;
}
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> x[i]; 
	}
	
	cout << dfs(1, 0, 0);
}
