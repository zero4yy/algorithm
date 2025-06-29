#include<bits/stdc++.h>
using namespace std;
int left_P[100005],right_T[100005]; 
string s;
//用数组记录P，T的个数 
//int main(){
//	cin>>s;
//	int len=s.length();
//	left_P[0]=0;
//	for(int i=1;i<len;i++){
//		if(s[i-1]=='P')
//			left_P[i]=left_P[i-1]+1;
//		else
//			left_P[i]=left_P[i-1];		
//	} 
//	right_T[len-1]=0;
//	for(int j=len-2;j>=0;j--){
//		if(s[j+1]=='T')
//			right_T[j]=right_T[j+1]+1;
//		else
//			right_T[j]=right_T[j+1];		
//	} 
//	int sum=0;
//	for(int i=1;i<=len-2;i++){
//		//cout<<left_P[i]<<" "<<right_T[i]<<endl;
//		if(s[i]=='A')
//		sum+=left_P[i]*right_T[i];
//	}
//	cout<<sum%1000000007;
//}
int main(){
	cin>>s;
	int sum,nump,numa,numt;
	sum=numa=nump=numt=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='T')
			numt++;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='P')
			nump++;
		else if(s[i]=='A')
			sum=(sum+nump*numt)%1000000007;
		else
			numt--;
	}
	cout<<sum;
	
}
