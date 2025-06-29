#include <iostream>
#include <vector>
/*
签：动态规划
遍历数组时计算当前最大值，不断更新
令imax为当前最大值，则当前最大值为 imax = max(imax * nums[i], nums[i])
由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
当负数出现时则imax与imin进行交换再进行下一步计算
时间复杂度：O(n)
*/
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, imax = 1, imin = 1;
        for(int num : nums) {
            if(num < 0) {
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax * num, num);
            imin = min(imin * num, num);

            ans = max(ans, imax);
        }
        return ans;
    }
};

int main() {

    return 0;
}