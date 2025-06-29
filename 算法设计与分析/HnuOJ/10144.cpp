#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>   
#include <cstring>
 
struct N
{
    char a[20]; int s;
} n1, n2, r;
 
int max(int a, int b) { return a > b ? a : b; }
 
int read(N& n)
{
    memset(n.a, 0, sizeof(n.a));
    char ch = getchar(); int i = 0;
    while (ch < '0' || ch > '9') { if (ch == -1) return -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { n.a[i++] = ch - '0'; n.s = i; ch = getchar(); }
    return 1;
}
 
void add(N& n1, N& n2)
{
    int a = 0, o = 0, s = max(n1.s, n2.s);
    r.s = s;
    for (int i = n1.s - 1, j = n2.s - 1; i >= 0 || j >= 0;)
    {
        if (i >= 0) a += n1.a[i--];
        if (j >= 0) a += n2.a[j--];
        o = a % 9;
        a /= 9;
        r.a[--s] = o;
    }
    if (a) printf("%d", a);
    for (int i = 0; i < r.s; ++i) printf("%d", r.a[i]);
    printf("\n");
}
 
int main()
{
    while (~read(n1) && ~read(n2)) add(n1, n2);
    return 0;
}