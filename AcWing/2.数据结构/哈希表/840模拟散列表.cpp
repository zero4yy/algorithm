/*
// 法一：拉链法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003; // 大于上限的第一个质数

int h[N], e[N], ne[N], idx;
int n, x;
string op;
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if(e[i] == x)
            return true;

    return false; 
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    while (n --)
    {   
        cin >> op >> x;
        if(op == "I") insert(x);
        else {
            if(find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } 
    }
    return 0;
}
*/


// 法二：开放寻址法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003; // 2~3倍
const int null = 0x3f3f3f3f;


int h[N];
int n, x;
string op;

int find(int x) {
    int k = (x % N + N) % N;

    while(h[k] != null && h[k] != x) {
        k ++;
        if(k == N) k = 0;
    }

    return k;
    
}

int main() {
    memset(h, 0x3f, sizeof h);
    cin >> n;
    while (n --)
    {   
        cin >> op >> x;
        if(op == "I") h[find(x)] = x;
        else {
            if(h[find(x)] == null) cout << "No" << endl;
            else cout << "Yes" << endl;
        } 
    }
    return 0;
}
