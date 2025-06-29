#include<bits/stdc++.h>
using namespace std;
int v[10005];
bool check(int& x){
	int sum=0;
	for(int i=1;i<=x;i++){
		if(x%i==0)
			v[sum++]=i;
	}
	if(sum<4) 
		return false;
	for(int i=0;i<sum;i++)
	{
		for(int j=i+1;j<sum;j++)
		{
			for(int k=j+1;k<sum;k++)
			{
				for(int l=k+1;l<sum;l++)
				{
					if((v[i]+v[j]+v[k]+v[l])%x==0)
						return true;
				}
			}
		}
	}
	return false;
}
int main(){
	
	int n,x; cin>>n;
	while(n--){
		cin>>x;
		if(check(x))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}	
}
