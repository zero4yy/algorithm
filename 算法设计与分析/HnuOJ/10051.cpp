#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
 
char s[3][10] = {"DEFICIENT", "PERFECT", "ABUNDANT"};
 
int calc(int n)
{
    int sum = 0;
    for (int i = 1; i < n; ++i)
        if (n % i == 0) sum += i;
    if (sum < n) return 0;
    else if (sum == n) return 1;
    return 2;
}
 
int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    while (~scanf("%d", &n) && n != 0)
    {
        printf("%5d  %s\n", n, s[calc(n)]);
    }
    printf("END OF OUTPUT\n");
    return 0;
}