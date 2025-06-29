#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.empty()) return {};
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<int> tmp;
        vector<vector<int>> res(r, vector<int>(c));

        for(int i = 0; i < m * n; i ++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }

        return res;
    }
};

int main() {

    return 0;
}
