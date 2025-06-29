#include <iostream>
#include <string.h>
using namespace std;


// 中心点扩展法
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int n = s.length();
        if(n == 1) return s;

        int maxlen = 1, st = 0;
        for(int i = 0; i < n; ++i) {
            int l1 = i, r1 = i;
            while(l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                int curlen = r1 - l1 + 1;
                if(curlen > maxlen) {
                    maxlen = curlen, st = l1;
                }
                l1--, r1++;
            }

            int l2 = i, r2 = i + 1;
            while(l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                int curlen = r2 - l2 + 1;
                if(curlen > maxlen) {
                    maxlen = curlen, st = l2;
                }
                l2--, r2++;
            }
        }
        return s.substr(st, maxlen);
    }
};

int main() {

    return 0;
}