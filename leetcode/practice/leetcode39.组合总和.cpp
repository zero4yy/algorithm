#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans; // 存储所有组合
    vector<int> path;
    int s = 0; // 当前路径和

    void dfs(vector<int>& candidates, int target, int dep) {     
        if(s == target) {
            ans.push_back(path);
            return;// 终止递归，避免继续搜索无效路径
        }
        if(s > target) return; // 剪枝

        int n = candidates.size();
        for(int i = dep; i < n; i ++) { // 继续从 `i` 位置搜索
            s += candidates[i];
            path.push_back(candidates[i]);

            // 递归，允许重复使用当前元素，因此是 i
            // dfs 顺序确保不会出现重复解。递归时，dep 只向后递增，保证组合内元素按固定顺序选取
            // 2 → 2 → 3 ✔️ (合法)
            // 2 → 3 → 2 ❌ (不会发生，因为递归只能向后)
            dfs(candidates, target, i); 

            // 回溯
            s -= candidates[i];
            path.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        dfs(candidates, target, 0);
        return ans;
    }
};

int main() {

}