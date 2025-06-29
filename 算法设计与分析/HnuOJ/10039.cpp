#include<iostream>
#include <algorithm>
#include<cstring>
using namespace std;
 
int main()
 
{
 
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 
    int i,j,n,m,num[1001];
    while(scanf("%d%d",&n,&m)!=EOF)
 
    {
 
        memset(num,0,sizeof(num));
        for(i=1; i<=n; i++)
            scanf("%d",num+i);
        j = m%n;
 
        for(i=1; i<=10; i++)
        {
            if(j == n)  j=0;
            printf("%d",num[j+1]);
            j++;
        }
        cout<<endl; 
    }
    return 0;
 
}