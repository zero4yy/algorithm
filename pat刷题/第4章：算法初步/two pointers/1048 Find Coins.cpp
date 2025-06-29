#include<bits/stdc++.h>
using namespace std;
int n,m;
int mon[100005];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>mon[i];
	sort(mon,mon+n);
	int i=0,j=n-1;
	while(i<j){
		if(mon[i]+mon[j]>m) j--;
		else if(mon[i]+mon[j]<m) i++;
		else break; 
	}
	if(i<j) cout<<mon[i]<<" "<<mon[j];
	else cout<<"No Solution";
}
