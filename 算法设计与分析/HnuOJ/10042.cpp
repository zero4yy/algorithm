#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
 
int a[10], ch, i = 0, l = 0;
 
int main()
{
    memset(a, 0, sizeof(a));
    printf("Spinlock Results\n");
    while (~(ch = getchar())) 
    {
        if (ch == '\n') l = i, i = 0;
        else if (ch == 'x') { for (int j = 0; j < l; ++j) printf("%d", a[j] % 10); printf("\n"); memset(a, 0, sizeof(a));}
        else if (ch == 'z') break;
        else a[i++] += ch - '0';
    }
    return 0;
}