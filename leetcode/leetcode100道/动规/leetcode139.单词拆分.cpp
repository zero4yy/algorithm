#include <iostream>
#include <vector>
#include <unordered_set>
#include <string.h>
using namespace std;
/*
爬楼梯模型 dp[i] 能否爬到第 i 层
爬楼梯的选择在 wordDict 中
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i ++) 
            for(string& wd : wordDict) {
                if(i >= wd.size() && dp[i - wd.size()] && s.substr(i - wd.size(), wd.size()) == wd)
                    dp[i] = true;
            } 
        return dp[s.size()];
    }
};

int main() {

    return 0;
}