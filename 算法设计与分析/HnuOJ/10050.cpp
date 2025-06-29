#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
int a[3005],b[3005];
using namespace std;
int main(){
    int n,i,flag;
    while(cin>>n){
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n-1;i++){
            b[i]=abs(a[i]-a[i+1]);
        }
        sort(b,b+n-1);
        flag=0;
        for(i=1;i<n;i++){
            if(b[i-1]!=i){
                flag=1;
                break;
            }
        }
        if(!flag)
        cout<<"Jolly"<<endl;
        else
        cout<<"Not jolly"<<endl;
    }
    return 0;
}