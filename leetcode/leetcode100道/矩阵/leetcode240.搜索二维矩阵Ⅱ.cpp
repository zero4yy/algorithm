#include <bits/stdc++.h>

using namespace std;

// dfs， 超时了
class Solution {
public:
    bool dfs(vector<vector<int>>& matrix, int target, int i, int j) {
        if(matrix.empty()) return false;
        if(i >= matrix.size() || j >= matrix[0].size()) return false;
        if(matrix[i][j] == target) return true;
        if(matrix[i][j] > target) return false;
        
        return dfs(matrix, target, i + 1, j) || dfs(matrix, target, i, j + 1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        return dfs(matrix, target, 0, 0);
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        // 从右上角开始搜索
        while(i < m && j >= 0) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j --;
            else i ++;
        }
        return false;
    }
};
    

int main() {

    return 0;
}