#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
背包问题变形:
正数 p
负数 -(sum-p)
p-(sum-p)=target
p= (sum+target)/2
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end()) + target;
        
        if(s < 0 || s % 2) return 0;
        int m = s / 2;
        
        vector<int> f(m + 1, 0);

        f[0] = 1;
        for(int num : nums) {
            for(int j = m; j >= num; j --) {
                f[j] = f[j] + f[j - num];
            }
        }
        return f[m];
    }
};

int main() {

    return 0;
}