#include<iostream>
using namespace std;
int a[10001];
int solve(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    for(int i=1;i<=10000;i++)
    a[i+solve(i)]=1;
    for(int i=1;i<=10000;i++)
        if(a[i]==0)
        cout<<i<<endl;
        return 0;
}