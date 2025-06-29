#include<bits/stdc++.h>
using namespace std;
const int N=1e4 + 5;
struct Ditan{
	int x, y, x2, y2;
}d[N];
int n, a, b, g, k, x, y;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++ ){
		cin>> a>> b>> g>> k;
		d[i]={a, b, a+g-1, b+k-1 };
	}
	cin >> x >> y;
	int ans=-1;
	for(int i=n-1;i>=0;i--){
		if(d[i].x <= x&& x<= d[i].x2 &&d[i].y <= y&& y<= d[i].y2)
		
		{
			ans = i + 1;
			break;
		}
		
	}
	cout<< ans <<'\n';
	return 0;
}
