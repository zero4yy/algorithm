#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
int n,m,x,y;
ll dp[25][25];
bool horse[25][25];
int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
int main(){
	cin >> n >>m >> x >> y;
	n++ , m++, x++ , y++ ;
	horse[x][y]=true;
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y + dy[i];
		if(xx>=1 &&xx<= n&&yy>= 1&&yy<=m )
			horse[xx][yy]=true;
	}
	
	dp[1][1]=1;
	for(int i=1;i<= n;i ++ ){
		for(int j=1;j<=m;j ++){
			if(i==1&&j==1) continue;
			
			dp[i][j]=dp[i-1][j] + dp[i][j-1];
			
			if(horse[i][j]) dp[i][j]=0;
			//cout<<dp[i][j]<<endl;

		}
	}
	
	cout<<dp[n][m];
}
