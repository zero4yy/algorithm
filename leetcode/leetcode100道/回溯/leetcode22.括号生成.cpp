#include <bits/stdc++.h>

using namespace std;

// 有效组合：前缀，( 的个数要大于等于 ) 的个数
class Solution {
public:
    vector<string> ans;
    // i 代表当前已选括号数
    // left 表示已选左括号数
    void dfs(string path, int n, int i, int left) {
        if(i == 2 * n) {
            ans.emplace_back(path);
            return;
        }

        if(left < n) {
            path[i] = '(';
            dfs(path, n, i + 1, left + 1);
        } 
        if(i - left < left) { // 左括号 >= 右括号
            path[i] = ')';
            dfs(path, n, i + 1, left);
        }
    }
    vector<string> generateParenthesis(int n) {
        int m = 2 * n;
        string path(m, 0);
        dfs(path, n, 0, 0);

        return ans;
    }
};

int main() {

}