#include<bits/stdc++.h>
using namespace std;
int main(){
	int n ;  cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	sort(a,a+n);
	sort(b,b+n);
	int height=a[0],height2=b[n-1];
	if(height>height2){
		cout<<"Yes"<<" "<<height-height2;
	}
	else{
		cout<<"No"<<" "<<height2-height+1;
	}
} 
