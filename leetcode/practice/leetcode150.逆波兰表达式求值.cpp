#include <bits/stdc++.h>

using namespace std;
/*
比较简单：
辅助栈
读到运算符时，弹出栈顶两个元素，进行运算，将结果压栈
最终栈顶元素即为ans
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int x, y, out;
        for(string token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                y = st.top(); st.pop();
                x = st.top(); st.pop();
                
                if(token == "+") out = x + y;
                else if(token == "-") out = x - y;
                else if(token == "*") out = x * y;
                else out = x / y;

                st.push(out);
            } else {
                int num = stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};

int main() {

    return 0;
}