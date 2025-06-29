// 经典题目
#include <bits/stdc++.h>

using namespace std;

// [2,3,1,1,4]
// 维护当前位置能走的最大步数，每走一步，减1
// 并比较当前位置的最大步数，判断是否需要更新
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0], i = 1;
        for(; cur != 0 && i < n; i ++) {
            cur --;
            if(cur < nums[i]) 
                cur = nums[i];
        }
        return i == n;
    }
};

int main() {

    return 0;
}