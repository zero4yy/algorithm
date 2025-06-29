#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/*
f[n] = min(f[n], f[n - coins[i]] + 1)
*/
class Solution {
public:
    int f[10005];
    int coinChange(vector<int>& coins, int amount) {
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int i = 1; i <= amount; i ++) 
            for(int coin : coins) {
                if(i < coin) continue;
                f[i] = min(f[i], f[i - coin] + 1);
            }

        // for(int coin : coins) 
        //     for(int j = coin; j <= amount; j ++) 
        //         f[j] = min(f[j], f[j - coin] + 1);

    if(f[amount] == 0x3f3f3f3f) return -1;
    return f[amount];
    }
};

int main() {
    
    return 0;

}