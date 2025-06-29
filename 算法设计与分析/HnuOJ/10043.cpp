#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <limits.h>  
using namespace std;  
const int maxn = 125;  
int k, p, t;  
int s[(1 << 20) + 10];  
int dp[(1 << 20) + 10], cost[maxn];  
int m, n;  
void init() {  
    t = 0; 
    memset(s, 0, sizeof(s)); 
    for (int i = 1; i <= n; i++) {  
        scanf("%d", &cost[i]);  
        s[i] = (1 << (i - 1)); 
    }  

    // Read the number of bundles  
    scanf("%d", &m);  
    // Input bundles  
    for (int i = 1; i <= m; i++) {  
        scanf("%d", &cost[i + n]);  
        scanf("%d", &k); 
        for (int j = 1; j <= k; j++) {  
            scanf("%d", &p); // Tap index  
            s[i + n] |= (1 << (p - 1)); 
        }  
    }  
    scanf("%d", &k);  
    for (int i = 1; i <= k; i++) {  
        scanf("%d", &p); 
        t |= (1 << (p - 1)); 
    }  
}  

void solve() {  
    for (int i = 0; i < (1 << n); i++)  
        dp[i] = INT_MAX;  
    dp[0] = 0; 
    int ans = INT_MAX; 
    for (int i = 0; i < (1 << n); i++) {  
        for (int j = 1; j <= n + m; j++) {  
            dp[i | s[j]] = min(dp[i | s[j]], dp[i] + cost[j]);  
          
            if (((i | s[j]) & t) == t) {  
                ans = min(ans, dp[i | s[j]]);  
            }  
        }  
    }  


    printf("%d\n", ans);  
}  

int main() {  
    
    while (true) {  
        scanf("%d", &n);  
        if (n == 0)
            break;   

        init(); 
        solve(); 
    }  
    return 0;  
}