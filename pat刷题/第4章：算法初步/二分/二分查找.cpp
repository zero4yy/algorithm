#include<bits/stdc++.h>
using namespace std;
int l,r,mid,k;
int binarySearch(vector<int>& num,int k){
	while(l<r){
		mid=(l+r+1)/2; //��������ѭ���������mid=(l+r)/2,��������ѭ���� 
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
