#include<bits/stdc++.h>
using namespace std;
int res[105][105],ress[105][105],n,k,x;
int main(){
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
				cin>>res[i][j];
				ress[i][j]=res[i][j];
			}
		
	int flag=0;	
	for(int i=1;i<=n;i+=2){
		int y=flag+1;
		for(int j=y+1;j<=n;j++){			
			res[i][j]=ress[i][j-y];
		}
		for(int l=1;l<=y;l++)
			res[i][l]=x;
		flag=(flag+1)%k;
	} 
	
//	for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//		cout<<res[i][j]<<" ";
//		cout<<endl;
//		}
	int sum;
	for(int j=1;j<n;j++){
		sum=0;
		for(int i=1;i<=n;i++)
		sum+=res[i][j];
		
		cout<<sum<<" ";
	}
	sum=0;
	for(int i=1;i<=n;i++)
	sum+=res[i][n];
	cout<<sum;
}
