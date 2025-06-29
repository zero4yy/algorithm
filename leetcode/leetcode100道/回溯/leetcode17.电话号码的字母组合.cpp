#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

class Solution {
    public:
        vector<string> ans = {};
        string path;
        string h[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
        void dfs(string digits, int dep) {
            int n = digits.length();
            if(dep == n) {
                ans.push_back(path);
                return;
            }
            string s = h[digits[dep] - '0'];
            for(char ch : s) {
                path[dep] = ch;
                dfs(digits, dep + 1);
            }
            return;
        }
        vector<string> letterCombinations(string digits) {
            if(digits.length() == 0) return ans;
            path.resize(digits.length(), ' ');
            dfs(digits, 0);
            return ans;
        }
    };


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string digits = "235";
    Solution sl;
    vector<string> ans = sl.letterCombinations(digits);

    for(string x : ans) cout << x << endl;

    return 0;
}