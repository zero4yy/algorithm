#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=0,l,i,j;
    char s[1000],a[1000];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(s);
        l=strlen(s);
        j=0;
        for(i=0;i<=l;i++)
        {
            if(s[i]!=' '&&s[i]!='\0')
                a[j++]=s[i];
            else
            {
                for(k=j-1;k>=0;k--)
                    printf("%c",a[k]);
                if(s[i]!='\0')
                    printf(" ");
                j=0;
            }
          }
        printf("\n");
    }
    return 0;
}