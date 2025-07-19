#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(s[i] == rs[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return n - dp[n][n];
    }
};

int main() {
    string s;
    while(cin >> s) {
        Solution sl;
        cout << sl.minInsertions(s) << endl;
    }
    return 0;
}