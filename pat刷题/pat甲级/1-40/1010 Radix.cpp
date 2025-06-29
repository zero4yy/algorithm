#include<bits/stdc++.h>
using namespace std;
string s,t; 
int tag,radix;
map<char,int>m;
int trans(string s){
	int res=0,p=0;
	for(int i=s.size()-1;i>=0;i--,p++){
		res+=m[s[i]]*pow(radix,p);
	}
	return res;
}
int main(){
	for(char x='0';x<='9';x++)
		m[x]=(x-'0');
		int y=10;
	for(char x='a';x<='z';x++,y++){
		m[x]=y;
	}
	cin>>s>>t>>tag>>radix;
	int num1,num2;
	if(tag==1){
		num1=trans(s);
		
	}
	if(tag==2){
		num2=trans(t);
	}
	
} 
