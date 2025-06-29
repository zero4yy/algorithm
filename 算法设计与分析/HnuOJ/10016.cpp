#include<stdio.h>
#include<string.h>
#define P 3.14159
int main()
{
    char str1[10],str2[10];
    int x,y,z;
    while(gets(str1)&&scanf("%d %d %d\n",&x,&y,&z)&&gets(str2))
    {
        if(strcmp(str1,"START")==0&&strcmp(str2,"END")==0)
        {
            double a,b,c;
            if(z>180) z=360-z;
            a=2*(z*P*x)/180;//a是总路程，总路程包含去程和返程的距离
            b=y*5;
            c=y-a/5;
            if(b<a) printf("NO %d\n",(int)b);
            else printf("YES %d\n",(int)c);
        }
    }
    return 0;
}