#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
中序遍历 得到递增有序数组
    5
   / \
  3   7
     / \
    4   8 
*/
class Solution {
public:
    long long pre_val = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(!isValidBST(root->left)) return false;

        if(root->val <= pre_val) return false; //当前节点小于pre, 不合法
        pre_val = root->val; //更新pre

        return isValidBST(root->right);
    }
};

int main() {

    return 0;
}