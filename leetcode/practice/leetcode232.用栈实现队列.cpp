#include <bits/stdc++.h>

using namespace std;
/*
入队栈 出队栈
两次LIFO 实现 FIFO
A B C pop D E pop pop pop pop
stIn: A B C

pop
stIn:
stOut:C B A, 弹出A
*/
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        int ans = peek();
        stOut.pop();
        return ans;
    }
    
    int peek() {
        if(stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        
        return stOut.top();
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {

    return 0;
}