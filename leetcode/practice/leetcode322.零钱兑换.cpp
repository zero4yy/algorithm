#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/*
完全背包问题, 物品的容量 即 硬币面值, 价值都为 1, 最终价值最小
f[n] = min(f[n], f[n - coins[i]] + 1)
*/
class Solution {
public:
    int f[10005];
    int coinChange(vector<int>& coins, int amount) {
        memset(f, 0x3f, sizeof f);
        f[0] = 0;

        for(int coin : coins) 
            for(int j = coin; j <= amount; j ++) 
                f[j] = min(f[j], f[j - coin] + 1);

    if(f[amount] == 0x3f3f3f3f) return -1;
    return f[amount];
    }
};

int main() {
    
    return 0;

}