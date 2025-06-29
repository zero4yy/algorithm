#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3 + 5;
int f[N];
int main(){
	int n ; cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			f[i]+=f[j];
		}
		f[i]++;
	}
	cout<<f[n];
}
//ll res=1;
//void func(int n){
//	for(int i=1;i<=n/2;i++){
//		res++;
//		func(i);
//	}
//	if(n==1)
//	return ;
//}
//int main(){
//	int n; cin >> n;
//	func(n);
//	cout<<res;
//}µÝ¹é³¬Ê± 
 
//int main(){
//	queue<int> q;
//	int n ; cin >> n;
//	q.push(n);
//	int cur, res = 1;
//	while(!q.empty()){
//		cur = q.front();
//		q.pop();
//		for(int i = 1; i <= cur/2; i ++ ){
//			res++;
//			if(i!=1 ) q.push(i);
//			
//		}
//		
//	}
//	cout << res <<'\n';
//}³¬Ê±
