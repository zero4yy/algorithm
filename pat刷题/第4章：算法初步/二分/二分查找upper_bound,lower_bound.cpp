#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[]={1,3,5,8,10,15,16};
	int* it=lower_bound(a,a+7,8);
	cout<<*it<<endl;
	vector<int>num(a,a+7);
	vector<int>::iterator iter=upper_bound(num.begin(),num.end(),20);
	cout<<*iter;
	//upper_bound()���ش���
	//lower_bound()���ش��ڵ��� 
} 
