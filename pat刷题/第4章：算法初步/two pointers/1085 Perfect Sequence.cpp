
#include<bits/stdc++.h>
using namespace std;
int n,p;
int main(){
	cin>>n>>p;
	int* num=new int [n];
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num,num+n);
	int i=0,j=0,res=0;
	while(i<n&&j<n){
		while(j<n&&num[j]<=(long long)p*num[i] ){
			j++;
			res=max(res,j-i);
		}
		i++;
	}
	delete[]num;
	cout<<res;
} 
