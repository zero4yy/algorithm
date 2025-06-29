//暴力算法，超时了 
#include<bits/stdc++.h>
using namespace std;
int dis[100005],from_one[100005];
int main(){
	int n,sum=0; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dis[i];
		sum+=dis[i];
		from_one[i]=sum;
	}
	
	int m; cin>>m;
	int s,e;
	for(int i=0;i<m;i++){
		cin>>s>>e;
		if(s>e) swap(s,e);
		int min_dis=0;
		min_dis=from_one[e-1]-from_one[s-1];
		
		min_dis=min(min_dis,sum-min_dis);
		cout<<min_dis<<endl;
	}
}
