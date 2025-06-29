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


// 递归，计算左子树和右子树的深度，然后取两者中的最大值
// 再加上根节点本身的深度（即1）。
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) {return 0;}

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};



int main() {

}