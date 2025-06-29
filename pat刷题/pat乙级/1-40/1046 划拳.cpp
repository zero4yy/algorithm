#include<bits/stdc++.h>
using namespace std;
int main(){
	pair<int,int>jia;
	pair<int,int>yi;
	int jiaa,yii;
	jiaa=yii=0;
	int N; cin>>N;
	while(N--){
		cin>>jia.first>>jia.second>>yi.first>>yi.second;
		if(jia.second==jia.first+yi.first&&jia.second!=yi.second)
			yii++;
		if(yi.second==jia.first+yi.first&&jia.second!=yi.second)
			jiaa++;
	//	if(jia.second==jia.first+yi.first&&yi.second==jia.first+yi.first)
		
	}
	cout<<jiaa<<" "<<yii;
}
