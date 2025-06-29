#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归，区间处理：左闭右开
class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if(left == right) return nullptr;

        int m = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = dfs(nums, left, m), root->right = dfs(nums, m + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};



int main() {

}