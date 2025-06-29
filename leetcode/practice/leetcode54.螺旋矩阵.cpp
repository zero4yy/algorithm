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
            
            for(int i = u + 1; i <= d; i ++) res.push_back(matrix[i][r]);
            // r --, u ++
            for(int i = r - 1; i >= l && d > u; i --) res.push_back(matrix[d][i]);

            for(int i = d - 1; i >= u + 1 && l < r; i --) res.push_back(matrix[i][l]);
            l ++; r --; u ++; d --;
        }
        return res;
    }
};

int main() {

    return 0;
}