//动态规划，自底向上 
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int num[1000][1000],dp[1000][1000];
int main(){
int t;cin>>t;
     while(t--){
    int n; cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>num[i][j];
    a[1]=num[1][1];

    for(int j=1;j<=n;j++)
        dp[n][j]=num[n][j];
        
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
            
    cout<<dp[1][1]<<endl;
  }
}