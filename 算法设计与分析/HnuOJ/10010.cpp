#include<iostream>
#include<map>
using namespace std;
int a[500001];
int main(){
    int k;
    map<int,int>maps;
    a[0]=0;
    maps[a[0]]=1;
    for(int i=1;i<=500000;i++){
        int b=a[i-1]-i;
        if(b>0&&maps.find(b)==maps.end())
        {
            a[i]=b;
            maps[a[i]]=1;
        }
        else
        {
            a[i]=a[i-1]+i;
            maps[a[i]]=1;
        } 
    }
    while(cin>>k&&k!=-1)
        cout<<a[k]<<endl;
}