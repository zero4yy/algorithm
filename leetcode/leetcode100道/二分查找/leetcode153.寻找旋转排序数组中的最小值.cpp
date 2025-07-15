#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left < right) {
            mid = (right - left) / 2 + left;
            if(nums[mid] > nums[right]) left = mid + 1; // mid-right 不是严格递增, 最小值在[mid+1, right]
            else right = mid; // nums[mid] < nums[right] 最小值在[left,mid]
        }
        return nums[left];
    }
};

int main() {

    return 0;
}