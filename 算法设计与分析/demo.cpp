#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1e3+10;
int n, a[maxn];
int dp[maxn];
 
void read()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}
 
void solve_v1() //O(n^2)
{
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 1; i < n; ++i)
        for(int j = i-1; j >= 0; --j)
            if(a[i] >= a[j] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
    for(int i = 0; i < n; ++i)
        ans = max(ans, dp[i]);
    printf("%d\n", ans+1);
}
 
void solve_v2() //O(nlogn)
{
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < n; ++i)
        *upper_bound(dp, dp+i, a[i]) = a[i];
    printf("%d\n", lower_bound(dp, dp+n, INF)-dp);
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        read();
        //solve_v1();
        solve_v2();
    }
    return 0;
}