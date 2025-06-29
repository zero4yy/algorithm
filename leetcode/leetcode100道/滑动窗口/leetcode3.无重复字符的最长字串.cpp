#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // a b d c d b f e a
        // i表示非重复子串最左边，j表示最右边
        int len = s.size();
        unordered_map<char, int> pos; // 存放字符最后出现的位置
        int i = -1, ans = 0;

        for(int j = 0; j < len; j ++) {
            if(pos.count(s[j])) {
                i = max(i, pos[s[j]]);
            }
            pos[s[j]] = j;
            ans = max(ans, j - i);

        }
        return ans;
    }
};
int main() {
    string s = "abdcdbfea";
    Solution sl;
    cout << sl.lengthOfLongestSubstring(s);
    return 0;
}