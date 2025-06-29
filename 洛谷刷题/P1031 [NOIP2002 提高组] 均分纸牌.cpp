#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int card[N];
int main(){
	int n, sum=0, ans=0; cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> card[i];
		sum += card[i];
	}
	int arr=sum/n;
	for(int i = 1; i <= n ;i++) {
		// 小于arr，从右边拿 
		if(card[i] < arr) {
			card[i+1]-=(arr - card[i]);
			ans ++;
		}
		// 大于arr，给右边 
		if(card[i] > arr) {
			card[i+1]+=(card[i] - arr);
			ans ++;
		}
	}
	
	cout << ans;
}
