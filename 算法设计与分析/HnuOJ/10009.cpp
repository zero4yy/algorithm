#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 100
#define BASE 10000
void multiply(int a[],int Max,int b)
{//大数乘法 
    int i,array=0;
    for(i=Max-1;i>=0;i--)
    {
        array += b*a[i];
        a[i] = array%BASE;
        array /= BASE;        
    }
}
 
void divide(int a[],int Max,int b)
{//大数除法 
    int i,div=0;
    for(i=0;i<Max;i++)
    {
        div =div * BASE + a[i];
        a[i] = div/b;
        div%=b;    
    }
}
 
 
int main()
{
    int i,j,n;
    int a[105][MAX];
    memset(a[1],0,sizeof(a[1]));
    for(i=2,a[1][MAX-1]=1;i<=100;i++)
    {
        memcpy(a[i],a[i-1],sizeof(a[i-1]));
        multiply(a[i],MAX,4*i-2);
        divide(a[i],MAX,i+1);
    }
    while(cin>>n,n!=-1)
    {
        for(i=0;i<MAX && a[n][i]==0;i++);
        cout<<a[n][i++];
        for(;i<MAX;i++)
            printf("%04d",a[n][i]);
        cout<<endl;
    }
    
    return 0;
}