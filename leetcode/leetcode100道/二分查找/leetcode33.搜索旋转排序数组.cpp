#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid;

        while(left < right) {
            mid = (right - left) / 2 + left;
            if(nums[mid] == target) return mid;

            // target在左半段
            if(nums[0] <= target) {
                if(nums[mid] < nums[0]) nums[mid] = INT_MAX; //mid在右, 改写为inf
            } 
            // target在右半段
            else {
                if(nums[mid] >= nums[0]) nums[mid] = INT_MIN; //mid在左, 改写为-inf
            }

            if(nums[mid] < target) left = mid + 1;
            else right = mid; 
        }
        return -1;
    }
};

int main() {

    return 0;
}