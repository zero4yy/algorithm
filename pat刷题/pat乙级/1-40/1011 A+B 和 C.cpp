#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
	int T; cin>>T;
	int sum=1;
	while(sum<=T){
		cin>>a>>b>>c;
		if(a+b>c)
			cout<<"Case #"<<sum<<": true"<<endl;
		else
			cout<<"Case #"<<sum<<": false"<<endl;
	
		sum++;
	}
}
