//#include<bits/stdc++.h>
//using namespace std;
//int price[10005];
//int n,cash;
//int main(){
//	cin>>n>>cash;
//	int sum=0;
//	for(int i=0;i<n;i++)
//		{
//			cin>>price[i];
////			if(price[i]<=cash)
////				sum++;
//		}
//	int res;
//	for(int i=0;i<n;i++)
//	{
//		res=0;
//		for(int j=i;j<n;j++){
//			res+=price[j];
//			if(res<=cash)
//				sum++;
//			else
//				break;
//		}
//	}
//	cout<<sum<<endl;
//}

#include<bits/stdc++.h>
//若购买土地可以不连续，01背包问题 
using namespace std;
int price[10005],dp[10005];
int n,cash;
int main(){
	cin>>n>>cash;
	int sum=0;
	for(int i=1;i<=n;i++)
		{
			cin>>price[i];
		}
	for(int i=1;i<=n;i++)
		for(int j=cash;j>=price[i];j--){
			dp[j]=max(dp[j],dp[j-price[i]]+price[i]);
		}
	
	cout<<dp[cash];
}

