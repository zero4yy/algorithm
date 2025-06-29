#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m; cin>>n>>m;
	m=m%n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=n-m;i<n;i++)
		cout<<a[i]<<" ";
	for(int i=0;i<n-m-1;i++)
	cout<<a[i]<<" ";
	cout<<a[n-m-1];
}
