#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, n;
int main(){
	cin >> n;
	map<int , int> m;
	for(int i = 0; i <n ; i++){
		cin >> a;
		if(m.find(a) == m.end())
			m[a] = 1;
		else 
			m[a] ++;
	}
	for( auto &it : m){
		cout << it.first << " " << it.second << endl;
		
	}
}