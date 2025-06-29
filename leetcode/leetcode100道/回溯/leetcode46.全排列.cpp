#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> vt;
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int dep) {
        int n = nums.size();
        if(dep == n) {
            ans.push_back(path);
            return;
        }
        
        for(int i = 0; i < n; i ++) {
            if(!vt[i]) {
                path[dep] = nums[i];
                vt[i] = true;
                dfs(nums, dep + 1);
                vt[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vt = vector<bool>(nums.size(), false);
        path = vector<int>(nums.size(), 0);
        dfs(nums, 0);
        return ans;
    }
};
int main() {
    vector<int>nums = {1, 5, 3};
    Solution sl;
    vector<vector<int>> ans = sl.permute(nums);
    for(auto x : ans)
    {
        for(auto y : x)
            cout << y << ' ';
        cout << endl;
    }
    return 0;
}