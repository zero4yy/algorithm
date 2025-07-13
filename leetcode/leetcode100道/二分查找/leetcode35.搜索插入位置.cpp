#include <bits/stdc++.h>

using namespacd std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        // [lefr, right) 左闭右开
        int mid;
        while(left < right) {
            mid = (right - left) / 2 + left;
            if(nums[mid] > target) right = mid;
            else if(nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return left; // left = right = mid + 1
    }
};

int main() {

    return 0;
}