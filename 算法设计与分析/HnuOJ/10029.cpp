#include <stdio.h>
 
bool solve()
{
    int n;
    scanf("%d", &n);
    if(!n) return 0;
    printf("\n");
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            printf("%d ", ((i+j+(n-3)/2)%n)*n+(i-j+(3*n-1)/2)%n+1);
        printf("\n");
    }
    return 1;
}
 
int main()
{
    while(solve());
    return 0;
}