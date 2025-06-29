#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> Cursubset;
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int dep) {
        int n = nums.size();
        ans.push_back(Cursubset);

        for(auto y : Cursubset) cout << y << ' ';
        cout << endl;
        
        for(int i = dep; i < n; i ++) {
            Cursubset.push_back(nums[i]);
            backtrack(nums, i + 1);
            Cursubset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
int main() {
    vector<int>nums = {1, 2, 3};
    Solution sl;
    vector<vector<int>> ans = sl.subsets(nums);
    for(auto x : ans) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
    return 0;
}