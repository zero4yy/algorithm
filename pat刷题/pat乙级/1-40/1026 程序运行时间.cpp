#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
	cin>>c1>>c2;
	int c=round((c2-c1)/100.0);
	//cout<<c;
	//cout<<c/3600<<":"<<c/60%60<<":"<<c%60;
	printf("%02d:%02d:%02d",c/3600,c/60%60,c%60);
}
