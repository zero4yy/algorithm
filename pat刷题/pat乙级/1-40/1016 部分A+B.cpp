#include<bits/stdc++.h>
using namespace std;
int main(){
	string A,B;
	char a,b;
	cin>>A>>a>>B>>b;
	int num=0,num2=0;
	for(int i=0;i<A.size();i++){
		if(A[i]==a){
			num++;
		}
	}
	string s=string(num,a);
	int c=atoi(s.c_str());
	for(int i=0;i<B.size();i++){
		if(B[i]==b){
			num2++;
		}
	}
	string t=string(num2,b);
	int v=atoi(t.c_str());
	cout<<v+c<<endl;
}
