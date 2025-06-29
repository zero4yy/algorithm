#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<pair<int, int>> pos;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == 0)
                    pos.push_back(make_pair(i, j)); 
            }
        }

        for(auto tar : pos) {
            int x = tar.first, y = tar.second;
            for(int j = 0; j < n; j ++) matrix[x][j] = 0;
            for(int i = 0; i < m; i ++) matrix[i][y] = 0;
        }
    }
};

int main() {

    return 0;
}