#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	if(getchar()=='C'){
		getchar();//ÎüÊÕ»Ø³µ 
		getline(cin,s);
		int sum=1,i=0;
		while(s[i]!='\0'){
			//if(s[i]==' ') cout<<" ";
			if(s[i]!=s[i+1]){
				if(sum==1)
					cout<<s[i];
				else
					{
						cout<<sum<<s[i]; 
						sum=1;
					}
			}			
			else{
				sum++;
			}
			//cout<<sum<<endl;
			i++;
		}
	}
	else{
		getchar();
		getline(cin,s);
		int res=0,i=0;
		while(s[i]!='\0'){
			if(s[i]>='0'&&s[i]<='9'){
				res=res*10+s[i]-'0';
			}
			else{
				if(res==0)
					cout<<s[i];
				else
					{
						cout<<string(res,s[i]);
						res=0;
					}
					
			}
			i++;
		}
	}
}
