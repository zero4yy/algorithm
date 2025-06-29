#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool judge(string s){
    int l=s.size();
    for(int i=0,j=l-1;i<=j;i++,j--){
        if(s[i]==s[j]||abs(s[i]-s[j])==32)
            continue;
        else
            return false;
    }
    return true;
}
int main(){
    string s;
    while(cin>>s){
        if(judge(s))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}