#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string> > ans;
    vector<string> path;
    int len;
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void dfs(string s, int i) {
        if(i == len) {
            ans.push_back(path);
            return;
        }
		
        for(int j = i; j < len; j ++) {
            // 如果是，则将其加入到路径中，如果不是，则直接跳过，尝试更长的子串
            if(isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);// 递归：对剩余的字符串部分进行分割
                path.pop_back();// 回溯：撤销选择，将刚才加入的子串弹出
            }
        }

    }
    vector<vector<string>> partition(string s) {
        len = s.size();
        dfs(s, 0);
        return ans;
    }
};

int main() {

    return 0;
}