#include<iostream>
using namespace std;
int main() {
    int n,m;
    while(cin>>n>>m) {
        int sum=n,temp,left=n,yu=0;
        while(1) {
            temp=left+yu;
            left=temp/m;
            if(left==0)//如果剩余烟头不满足能形成新的烟，就跳出循环
                break;
            yu=temp%m;
            sum+=left;
        }
        cout<<sum<<'\n';
    }
}