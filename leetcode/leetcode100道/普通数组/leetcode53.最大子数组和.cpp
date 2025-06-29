#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        
        for(int num : nums) {
            if(sum >= 0) sum += num;
            else sum = num;
            // // 或这样 思路其实一样
            // if(sum < 0) sum = 0;
            // sum += num;

            ans = max(sum, ans);
        }
        return ans;
    }
};

int main() {

    return 0;
}