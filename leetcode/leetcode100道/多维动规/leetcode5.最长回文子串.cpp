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
            // j=0,中心点奇数 j=1,中心点偶数
            for(int j = 0; j <= 1; j ++) {
                int l = i, r = i + j;
                while(l >= 0 && r < n && s[l] == s[r]) {l --, r ++;}
                
                l ++, r --;   

                if(maxlen < r - l + 1) {
                    maxlen = r - l + 1;
                    st = l;
                }
            }
        }

        return s.substr(st, maxlen);
    }
};

// dp 优化 
// 优化了个寂寞 耗时反而增加。。。
class Solution2 {
public:
    string longestPalindrome(string s) {

    }
};
int main() {

    return 0;
}