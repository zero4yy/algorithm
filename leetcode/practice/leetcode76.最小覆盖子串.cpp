#include <bits/stdc++.h>
using namespace std;
//A-Z 65-90
//a-z 97-122
class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        
        int m = s.length(), n = t.length();
        if(m < n) return "";
        unordered_map<char, int> hs, ht;
        for(char ch : t) ht[ch] ++;

        for(int i = 0, j = 0, cnt = 0; i < m && j <= i; i ++) {
            if(++hs[s[i]] <= ht[s[i]]) cnt ++;
            
            while(hs[s[j]] > ht[s[j]] && j < i) hs[s[j++]]--;

            if(cnt == n) {
                if(ans.empty() || ans.length() > i - j + 1) 
                    ans = s.substr(j, i - j + 1);
            }

        }
        return ans;
    }
};
int main() {
    Solution ss;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << ss.minWindow(s, t);
    return 0;
}
