#include <bits/stdc++.h>

using namespace std;

// 遇到[，数字 字符串入栈
// 遇到]，数字 字符串弹栈
class Solution {
public:
    string decodeString(string s) {
    stack<int> nums;
    stack<string> strs;
    string ans, ss;
    int num = 0;
    for(char &c : s) {
        if(c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            ss += c;
        }
        if(c == '[') {
            nums.push(num);
            num = 0;
            
            strs.push(ss);
            ss = "";
            
        }
        if(c == ']') {
            int times = 0;
            times = nums.top();
            nums.pop();
            
            for(int i = 0; i < times; i ++) {
                strs.top() += ss;
            }
            ss = strs.top();
            strs.pop();
        }

    }

    return ss;
    }
};

int main() {

    return 0;
}