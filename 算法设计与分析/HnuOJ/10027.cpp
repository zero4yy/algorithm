#include <stdio.h>
#include <algorithm>

const int MAX_N = 50005;

int a[MAX_N], dp[MAX_N], n;

template <typename T>
inline T read_int(T& n)
{
    bool f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') !f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { n = (n << 1) + (n << 3) + ch - '0'; ch = getchar(); }
    n = f ? n : ~(n-1);
}

template <typename T>
int m_lower_bound(T a[], int left, int right, T target)
{
    int l = left, r = right;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (a[m] == target)
        {
            if (m == left || m != left && a[m-1] != target) return m;
            r = m - 1;    
        }
        else if (a[m] > target) r = m - 1; 
        else if (a[m] < target) l = m + 1;        
    }
    return l <= right ? l : -1;
}


int solve()
{
    int max_pos = 0;
    dp[max_pos] = a[0];
    for (int i = 1 ; i < n ; ++i) 
    {
        if (a[i] > dp[max_pos]) dp[++max_pos] = a[i];
        //else dp[m_lower_bound(dp, 0, max_pos, a[i])] = a[i];   // 比 STL 慢 15ms 
        else dp[std::lower_bound(dp, dp+max_pos+1, a[i])-dp] = a[i];    
    }
    return max_pos + 1;
}


int main()
{
    read_int(n);
    for (int i = 0 ; i < n ; ++i) read_int(a[i]);  
    printf("%d", solve());
    return 0;
}