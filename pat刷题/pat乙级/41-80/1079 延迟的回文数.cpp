#include<bits/stdc++.h>
using namespace std;
char sum[1005];
bool huiwen(int& len){
	for(int i=0,j=len;i<=j;i++,j--){
		if(sum[i]!=sum[j]) return false;
	}
	return true;
}
int main(){
		string s;
		getline(cin,s);
		string t=s;
		reverse(s.begin(),s.end());
		cout<<t<<" "<<s<<endl;
		int len=t.size();
		int flag=0;//进位
		int k=0; //下标
		int c; 
		for(int i=len-1;i>=0;i--){
			c=(t[i]-'0')+(s[i]-'0')+flag;
			if(c>=10){
				sum[k++]=c%10+'0';
				flag=1;
			}
			else {
				sum[k++]=c+'0';
			}
		}
		for(int i=0;i<len+1;i++)
		cout<<sum[i];
		string ssum=sum;
		cout<<endl;
		cout<<ssum<<endl;
}
