#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(!st.empty()) {
                if(st.top() == '(' && c == ')' ||
                   st.top() == '[' && c == ']' ||
                   st.top() == '{' && c == '}'
                   ) 
                st.pop();
            else st.push(c);
            }
            else st.push(c);
        }

        return st.empty();
    }
};

int main() {

    return 0;
}