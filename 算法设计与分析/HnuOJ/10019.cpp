#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a[1100],b[1100],book[1100];
int main()
{
    int c=1,n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int i,j=0;
        if(m==0&&n==0)
        break;
        memset(book,0,sizeof(book));
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            book[a[i]]=1;//标记我们手中的牌
        }
        for(i=n*m;i>=1;i--)
        {
            if(book[i]==0)
            b[j++]=i;//求出剩余最大的牌，作为对手的牌
            if(j==m)//这里我们相当于把m个人的游戏看成两个人的游戏
            break;
        }
        sort(a,a+m);
        int s=0,k=0;
        for(i=m-1;i>=0;i--)//大与大的比
        {
            if(b[k]>a[i])
            k++;
            else//我们牌大必赢
            s++;
        }
        printf("Case %d: %d\n",c++,s);
    }
    
    return 0;
}