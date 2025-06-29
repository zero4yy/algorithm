#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    int n;
    // 判断回文串
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(int i, string s) {
        if(i == n) {
            ans.emplace_back(path);
            return;
        }

        for(int j = i; j < n; j ++) {
            if(isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        dfs(0, s);
        return ans;
    }
};

int main() {

    return 0;
}