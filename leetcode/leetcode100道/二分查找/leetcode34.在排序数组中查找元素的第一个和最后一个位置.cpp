#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        // 左开右开 (left,right)
        int left = -1, right = nums.size();
        int mid;
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid;
            else 
                right = mid;
        }
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if(start == nums.size() || nums[start] != target) 
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1; // 大于8的左边第一个 
        return {start, end};

    }
};

int main() {
    
    return 0;
}