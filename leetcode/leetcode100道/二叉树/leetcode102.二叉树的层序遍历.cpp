#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            vector<int> val;
            int n = q.size();
            while(n --) {
                TreeNode* node = q.front();
                q.pop();
                val.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.emplace_back(val);
        }
        return ans;
    }
};

int main() {


    return 0;
}