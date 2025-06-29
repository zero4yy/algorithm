#include <bits/stdc++.h>
using namespace std;

// 超级暴力，O(N_2 * logN)
class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int p_size = p.size();
        int s_len = s.size();
        string t;
        ranges::sort(p);
        for(int i = 0; i < s_len - p_size; i ++) {
            t = s.substr(i, p_size);
            ranges::sort(t);
            if(t == p) ans.push_back(i);
        }
        return ans;
    }
};

// O(N)
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> pch;
        unordered_map<char, int> cnt;
        int p_len = p.size();
        int s_len = s.size();
        for (char x : p)
            pch[x]++;

        int l = 0;
        for (int r = 0; r < s_len; r++) {
            while (r - l + 1 > p_len) {
                if (cnt[s[l]] == 1)
                    cnt.erase(s[l]);
                else
                    cnt[s[l]]--;
                l++;
            }
            cnt[s[r]]++;
            if (cnt == pch)
                ans.push_back(l);
        }
        return ans;
    }
};

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> ans;
            vector<int> pch(26, 0), cnt(26, 0);
            //使用固定大小的数组来代替 unordered_map，因为只处理小写字母，这样可以减少哈希表的开销。
            //使用 unordered_map 才击败了53%的人，:(，使用固定数组提高效率，成功击败100%


            int p_len = p.size();
            int s_len = s.size();

            if(s_len < p_len) return ans;

            for(char x : p) pch[x - 'a'] ++; // 记录p中字符出现的频率

            int l = 0;
            for(int r = 0; r < s_len; r ++) {
                cnt[s[r] - 'a'] ++;

                if(r - l + 1 > p_len) { // 区间长度大于 p 长度，右移l
                    cnt[s[l] - 'a'] --;
                    l ++;
                }
                if(cnt == pch) ans.push_back(l);
            }
            return ans;

        }
    };


int main() {

    return 0;
}