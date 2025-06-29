#include<bits/stdc++.h>
using namespace std;
//MAPÈÝÆ÷,SETÈÝÆ÷£¬vectorÈÝÆ÷Ó¦ÓÃ 
bool cmp(string a,string b){
	return a.substr(6,8)<b.substr(6,8);
}
int main(){
	int n; cin>>n;
	string id,birth;
	vector<string>school_mate;
	set<string>people;
	map<string,string>pp;
	for(int i=0;i<n;i++){
		cin>>id;
		school_mate.push_back(id);
	}
	int m; cin>>m;
	for(int i=0;i<m;i++){
		cin>>id;
		people.insert(id);
	}
	int sum=0;
	for(int i=0;i<school_mate.size();i++){
		if(people.find(school_mate[i])!=people.end()){
			sum++;
			birth=school_mate[i].substr(6,8);
			pp[birth]=school_mate[i];
		}
	}
	if(sum!=0){
		cout<<sum<<endl;
		cout<<pp.begin()->second<<endl;
	}
	else{
		cout<<0<<endl;
		vector<string>v(people.begin(),people.end());
//		set<string>::iterator it;
//		for(it)
		sort(v.begin(),v.end(),cmp);
		cout<<v[0]<<endl;
	}
}
