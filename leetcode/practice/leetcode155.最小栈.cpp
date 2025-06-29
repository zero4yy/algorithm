#include <bits/stdc++.h>

using namespace std;

// 维护前缀最小值
// preMin[i]=min(preMin[i−1],nums[i])
class MinStack {
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        min_st.emplace(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        min_st.push(min(val, min_st.top()));
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    cout << "hello";
    return 0;
}