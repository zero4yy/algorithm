#include<bits/stdc++.h>
using namespace std;
int l,r,mid,k;
int binarySearch(vector<int>& num,int k){
	while(l<r){
		mid=(l+r+1)/2; //避免了死循环，如果是mid=(l+r)/2,则会出现死循环啦 
		if(num[mid]==k) return mid;
		else if(num[mid]>k) r=mid;
		else l=mid; 
	}
	return -1;
}
int main(){
	int n; cin>>n;
	vector<int>num(n,0);
	for(int i=0;i<n;i++) cin>>num[i];
	cin>>k;
	l=0,r=n-1;
	 
	cout<<binarySearch(num,k);
}  
