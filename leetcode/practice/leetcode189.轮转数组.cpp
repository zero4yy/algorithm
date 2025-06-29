#include <bits/stdc++.h>

using namespace std;

/*
​​算法思路​​
​​反转整个数组​​：将数组完全反转，这样原本需要轮转的后 k 个元素会移动到数组前端。
​​反转前 k 个元素​​：将前 k 个元素反转回原来的顺序。
​​反转剩余 n-k 个元素​​：将剩下的 n-k 个元素反转回原来的顺序。
​​示例​​：

nums = [1, 2, 3, 4, 5], k = 2
1. 反转整个数组 -> [5, 4, 3, 2, 1]
2. 反转前 2 个元素 -> [4, 5, 3, 2, 1]
3. 反转剩余 3 个元素 -> [4, 5, 1, 2, 3]（最终结果）
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 三次反转法
        k = k % nums.size();
        if(k == 0) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

    }
};

int main() {
    Solution sol;
    vector<int> nums  {1, 2, 3, 4, 5};
    sol.rotate(nums, 2);
    for(int num : nums) cout << num << " ";
    return 0;
}