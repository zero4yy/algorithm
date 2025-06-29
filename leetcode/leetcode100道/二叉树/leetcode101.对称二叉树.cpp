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


class Solution {
public:
    // 在【100.相同的树】 基础上修改
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr) 
            return p == q;
        return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left); 
    }

    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};



int main() {

    return 0;
}