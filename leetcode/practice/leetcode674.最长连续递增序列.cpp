#include <iostream>
#include <vector>

using namespace std;
/*
遍历一遍数组即可
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int res = 1;
        for(int i = 0; i + 1 < n; i ++) {
            if(nums[i] < nums[i + 1]) res ++;
            else {
                ans = max(res, ans);
                res = 1;
            }
        }
        return max(ans, res);
    }
};

int main() {

    return 0;
}