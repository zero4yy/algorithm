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

// 递归
class Solution
{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root) {
        if(root != nullptr) {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
    }
};

// 迭代，使用栈模拟
class Solution2
{
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        TreeNode* curr = root;
        stack<TreeNode*> S;
        while(curr || S.size()) {
            // 遍历左子树
            while(curr) {
                S.push(curr);
                curr = curr->left;
            }
            // 访问根节点
            curr = S.top();S.pop();
            ans.push_back(curr->val);
            // 遍历右子树
            curr = curr->right;
        }
        return ans;
    }
};

int main() {

}