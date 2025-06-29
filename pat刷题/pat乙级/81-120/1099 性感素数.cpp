#include<bits/stdc++.h>
using namespace std;
//ËØÊıÅĞ¶Ï·½·¨ 
bool check(int x){
	if(x<=1) return false;
	if(x==2) return true;
	for(int i=2;i<=x/i;i++){
		if(x%i==0)
			return false;			
	}
	return true;
}
int main(){
	int n; cin>>n;
	string s;
	
	if(check(n)&&(check(n-6)||check(n+6))){
		s="Yes";
	}
	else{
		s="No";
	}
	
	if(s=="Yes"){
		cout<<s<<endl;
		if(check(n-6)){
			cout<<n-6<<endl;
		}
		else
			cout<<n+6<<endl;
	}
	else{
		cout<<"No"<<endl;
		while(1)
		{
			n++;
			if(check(n)&&(check(n-6)||check(n+6))){
			s="Yes";
			}
			else{
			s="No";
			}
			if(s=="Yes"){
			break;
		}
		}
		cout<<n<<endl;
	}
}
