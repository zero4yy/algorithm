#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp = matrix;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                matrix[j][n - i - 1] = tmp[i][j];
            }
        }
    }
};

int main() {
    
    return 0;
}