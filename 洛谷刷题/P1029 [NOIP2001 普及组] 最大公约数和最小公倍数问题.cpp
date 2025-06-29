#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//¹Ø¼üx*y=p*q 
ll gcd(int a, int b){
	return b==0 ? a : gcd(b, a % b);
}
ll lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(){
	int x, y,ans = 0;
	cin >> x >> y;
	for(int i = x;i <= y;i ++){
		int j = x * y / i;
		if(i * j != x * y) continue;
		if(gcd(i, j) == x && lcm(i, j)== y)
			ans++;	
	}
	cout << ans;
} 
