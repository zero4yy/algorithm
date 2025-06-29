#include<bits/stdc++.h>
using namespace std;
int n,p;
//upper_bound()快速解体 
//int main(){
//	cin>>n>>p;
//	int* num=new int [n];
//	for(int i=0;i<n;i++) cin>>num[i];
//	sort(num,num+n);
//	int res=1;
//	for(int i=0;i<n;i++){
//		int j=upper_bound(num+i+1,num+n,(long long)num[i]*p)-num;
//		res=max(res,j-i);
//	}
//	cout<<res<<endl;
//} 
int binarySearch(int& i,int* num){
	int l=i+1,r=n-1,mid;
	if(num[r]<=(long long)num[i]*p) return n;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		mid=(l+r+1)/2;
		//cout<<mid<<endl;
		if(num[mid]<=(long long)num[i]*p) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	cin>>n>>p;
	int* num=new int [n];
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num,num+n);
	int res=1,j;
	for(int i=0;i<n;i++){
		j=binarySearch(i,num);
		//cout<<j<<endl;
		res=max(res,j-i);
	}	
	cout<<res;
} 
