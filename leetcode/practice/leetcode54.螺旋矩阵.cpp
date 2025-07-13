#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int l = 0, r = n - 1, u = 0, d = m - 1;

        while(l <= r && u <= d) {
            for(int i = l; i <= r; i ++) res.push_back(matrix[u][i]);
            u++; // 收缩上边界

            for(int i = u; i <= d; i ++) res.push_back(matrix[i][r]);
            r--; // 收缩右边界

            for(int i = r; i >= l && d >= u; i --) res.push_back(matrix[d][i]); // d >= u 避免 只有1行时重复读取
            d--; //收缩下边界

            for(int i = d; i >= u && l <= r; i --) res.push_back(matrix[i][l]);
            l++; // 收缩左边界
        }
        return res;
    }
};

int main() {

    return 0;
}