#include <bits/stdc++.h>
using namespace std;

/*
法1
这道题主要用到思路是：滑动窗口
什么是滑动窗口？
其实就是一个队列,比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，
当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！

如何移动？
我们只要把队列的左边的元素移出就行了，直到满足题目要求！
一直维持这样的队列，找出队列出现最长的长度时候，求出解！
时间复杂度：O(n)

*/
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        unordered_set<char> chset;
        int left = 0, len = s.size(), ans = 0;

        for(int right = 0; right < len; right ++) {
            // find
            while(chset.find(s[right]) != chset.end()) {
                chset.erase(s[left]);
                left ++;
            }
            ans = max(ans, right - left + 1);
            chset.insert(s[right]);
        }
        return ans;
    }
};
/*
2
进一步优化，1中可能需要 while, 多次移动left
因此可以使用map，存放字符最后出现的位置，如果重复，直接使left移动至字符最后出现的位置即可
*/
class Solution2 {
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
            ans = max(ans, j - i); //i 从 -1 开始

        }
        return ans;
    }
};
int main() {
    string s = "abdcdbfea";
    Solution1 sl;
    cout << sl.lengthOfLongestSubstring(s);
    return 0;
}