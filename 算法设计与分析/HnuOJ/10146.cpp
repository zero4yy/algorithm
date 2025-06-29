#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        double k=0;
        for(int i=n;i>=1;i--)
        {
            k+=log10(i*1.0);//计算位数
        }
        printf("%d\n",int(k+1));
    }
    return 0;
}