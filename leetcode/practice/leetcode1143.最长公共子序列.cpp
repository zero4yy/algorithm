#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector f(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(s1[i] == s2[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                } else {
                    f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
                }
            }
        }
        return f[m][n];
    }
};

int main() {
    Solution sl;
    string s1 = "abcdefg", s2 = "acf";
    cout << sl.longestCommonSubsequence(s1, s2);
    return 0;
}