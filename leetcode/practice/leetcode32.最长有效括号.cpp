#include <bits/stdc++.h>

using namespace std;
/*
寻找最近出现的 (, 注意初始化 -1, 很重要
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        int len = s.size();
        for(int i = 0; i < len; i ++) {
            if(s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}