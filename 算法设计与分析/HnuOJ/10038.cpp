#include<iostream>
#include<cmath>
using namespace std;
int low(int& a){
    int res;
    double t=2;
    int k=a,z,sum=0;
    while(k!=0){
        z=k%2;
        k/=2;
        if(z==1)
            {
                res=pow(t,sum);
                break;
            }
        sum++;
    }
    return res;
}
int main(){
    int A;
    while(cin>>A&&A!=0)
    {
        cout<<low(A)<<endl;
    }
} 