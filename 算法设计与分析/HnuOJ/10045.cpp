#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring> 
#include<cstdlib>
#include <queue>
 
struct P
{
    P(int _i = 0, int _pass=0)
    {
        i = _i; pass = _pass;
    }
    int i, pass;
};
std::queue <P> q;
 
int main()
{
    int n, m, pass;
    P tmp, c;
    while (~scanf("%d%d", &n, &m) && n != 0 && m != 0)
    {
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &pass);
            tmp.i = i + 1; tmp.pass = pass;
            q.push(tmp);
        }
        while (!q.empty())
        {
            c.pass = m;
            while (!q.empty() && c.pass != 0) {
                tmp = q.front();
                q.pop();
                --c.pass;
                if (c.pass != 0) q.push(tmp);
                else { c = tmp; printf("%d", c.i); if (!q.empty()) printf(" "); else printf("\n"); };
            }
        }
    }
    return 0;
}