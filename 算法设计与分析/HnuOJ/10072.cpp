#include<iostream>
#include<vector>
using namespace std;
int a[50];
int main(){
    a[0]=0;
    a[1]=1;
    for(int i=2;i<=45;i++){
        a[i]=a[i-1]+a[i-2];
    }
    int t,n; cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n]<<endl;
    }
}