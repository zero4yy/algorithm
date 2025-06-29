#include<bits/stdc++.h>
using namespace std;
bool check(int a, int b, int c){
	set<int> st;
	while(a) st.insert(a%10),a/=10;
	while(b) st.insert(b%10),b/=10;
	while(c) st.insert(c%10),c/=10;
	
//	for(auto &it : st) if(it==0) return false;
	for(set<int> :: iterator it=st.begin(); it!= st.end() ; it ++ ){
		if( *it == 0) 
			return false;
	}
	return st.size() == 9;
}
int main(){
	int j, k;
	for(int i = 100; 3 * i <= 1000; i ++ ){
		j=2 * i, k = 3 * i;
		if(check(i, j, k))
			cout<< i << ' '<< j<< ' '<< k<<endl;
	}
} 
