#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len=s.size(),n1,n2,n3;
	if(s.size()%2==1){
		n2=len;
		n1=n3=0;
		while(n1<=n2&&n2>=3){
			
			if((len+2-n2)/2<=n2) {
				n1=n3=(len+2-n2)/2;
			}
			else
				break;
			n2-=2;
		}
	}
	else{
		n2=len;
		n1=n3=0;
		while(n1<=n2&&n2>=4){
			
			if((len+2-n2)/2<=n2) {
				n1=n3=(len+2-n2)/2;
			}
			else
				break;
			n2-=2;
		}
	}
	//cout<<n1<<" "<<n2<<" "<<n3<<endl; 
	string Kongbai=string(n2,' ');
	for(int i=0;i<n1-1;i++){
		cout<<s[i]<<Kongbai<<s[len-i-1]<<endl;
	}
	for(int i=n1-1;i<=n1+n2;i++){
		cout<<s[i];
	}
}
