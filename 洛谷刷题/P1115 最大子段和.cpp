#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N],dp[N],prefix[N];
int main(){
	int n; cin >> n;
	//Ç°×ººÍ 
//	for(int i = 1; i <= n; i++){
//		cin >> a[i];
//		prefix[i] = prefix[i-1] + a[i];
//	}
//	int res=a[1],mi=0;
//	for(int i = 1; i <= n; i++){
//		res = max(res, prefix[i]-mi);
//		mi= min (prefix[i], mi);
//		
//	}
//	
//	cout << res;
	//Ì°ÐÄ
	for(int i = 1; i <= n; i++) cin >> a[i];
	int  res=a[1],sum=0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
		res = max(res, sum);
		if(sum < 0) sum = 0;
	}	
	cout << res;
}
