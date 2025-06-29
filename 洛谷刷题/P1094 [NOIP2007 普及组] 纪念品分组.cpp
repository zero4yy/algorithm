#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e4 + 5;
int n , w;
int p[N];
int main(){
	cin >> w >> n;
	int ans = 0;
	for ( int i = 1; i <= n; i++){
		cin >> p[i];
	}
	sort(p + 1, p + 1 + n );
	int i = 1, j = n;
	while(i <= j){
		if(i != j && p[i] + p[j] <= w) i++;
		j-- ;
		ans ++;
	}
	cout << ans;
	return 0;
}