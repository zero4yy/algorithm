#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;
// 入栈
void push(int x) {
    stk[++ tt] = x;
}
// 出栈
void pop() {
    tt --;
}
// 判断是否为空
void empty() {
    if(tt) cout << "NO\n";
    else cout << "YES\n";
}
// 返回栈顶元素
int query() {
    return stk[tt];
}

int main() {
    int n; cin >> n;
    while(n --) {
        string s;
        cin >> s;
        if(s == "push") {
            int x; 
            cin >> x;
            push(x);
        }
        else if(s == "pop") pop();
        else if(s == "empty") empty();
        else cout << query() << endl;
    }

    return 0;
}