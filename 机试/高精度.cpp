#include <bits/stdc++.h>
using namespace std;
/*
long long 最大 9 x 10^18
*/

// 加法, 核心: 加法 进位
vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int alen = a.size(), blen = b.size();
    int t = 0; //进位
    for(int i = 0; i < alen || i < blen; i ++) {
        if(i < alen) t += a[i]; // 加 a 的当前位
        if(i < blen) t += b[i]; // 加 b 的当前位

        c.push_back(t % 10); // c的当前为位
        t /= 10; // 计算进位
    }
    if(t) c.push_back(t);
    return c;
}

/*
减法 a >= b
核心: 借位，相减
*/
vector<int> sub(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int alen = a.size(), blen = b.size();
    int ci, t = 0; // c 记录当前位, t 为借位

    for(int i = 0; i < alen; i ++) {
        ci = a[i] - t; // 减去借位
        if(i < blen) ci -= b[i]; // 减去 b[i]

        c.push_back((ci + 10) % 10); // 存储当前位, +10 是因为可能为负需要借位
        
        if(ci < 0) t = 1; //判断是否需要向高位借位，并更新借位标记t
        else t = 0;
    }
    // 去掉前导0
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
/*
乘法
*/
vector<int> mul(vector<int> &a, vector<int> &b) {
    // 1. 初始化结果vector，大小要足够长, 一般来说不会超过alen+blen
    vector<int> c(a.size() + b.size()+ 5);

    // 2. 计算各位的“裸积”并累加，不处理进位
    for(int i = 0; i < a.size(); ++i) 
        for(int j = 0; j < b.size(); ++j)
            c[i + j] += a[i] * b[j];

    // 3. 统一处理进位，与加法处理类似
    for(int i = 0, t = 0; i < c.size(); i ++) {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }

    // 去掉前导0
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    vector<int> a = {9,9,9};
    vector<int> b = {0};
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> c = mul(a, b);
    reverse(c.begin(), c.end());
    for(int x : c) cout << x;


    return 0;
}