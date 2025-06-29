#include<stdio.h>
#include<math.h>
#include<cstdio>
#include<algorithm>
using namespace std;
#define min(a,b) a <= b ? a : b;
double x,y,c;
double we(double w)
{
    return 1-c/sqrt(y*y-w*w)-c/sqrt(x*x-w*w);
}
int main()
{
    while(scanf("%lf%lf%lf",&x,&y,&c)!=-1)
    {
        double r,l=0;
        r=min(x,y);
        double mid;
        while(r-l>1e-8)
        {
            mid=(l+r)/2;
            if(we(mid)>0)
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        printf("%.3lf\n",mid);
    }
}