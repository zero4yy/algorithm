#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
 
 
int main()
{
    int ch; int p = 0;
    while (~(ch = getchar())) 
    {
        if (ch == '/') ++p;
        else if (ch == '.' && p == 2) printf("\n"), p = 0;
        else if (p == 2) printf("%c", ch);
        if (p == 1) printf("server: ");
    }
    return 0;
}