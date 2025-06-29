#include <bits/stdc++.h>

using namespace std;

/*
引入辅助栈 stack
遍历压栈序列 {
    a压入栈
    b循环出栈: 栈顶元素 == 出栈序列元素，弹出栈顶元素
}
最终 栈 空，合法
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;

        int j = 0;
        for(int i = 0; i < n; i ++) {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j] && j < n) {
                st.pop();
                j++;
            }            
        }
        if(st.empty()) return true;
        else return false;
    }
};

int main() {

    return 0;
}