#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int cur = 1;
        int l = 0, r = n - 1, u = 0, d = n - 1;

        while(l <= r && u <= d) {
            for(int i = l; i <= r; i ++) {matrix[u][i] = cur++;}
            u++;

            for(int i = u; i <= d; i ++) {matrix[i][r] = cur++;}
            r--;

            for(int i = r; i >= l && u <= d; i --) {matrix[d][i] = cur++;}
            d--;

            for(int i = d; i >= u && l <= r; i --) {matrix[i][l] = cur++;}
            l++;
        }
        return matrix;
    }
};

int main() {
    int n; cin >> n;
    Solution sl;
    vector<vector<int>> m = sl.generateMatrix(n);
    for(auto x : m) {
        for(int y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
    return 0;
}