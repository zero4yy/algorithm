// 实现题 2-3 半数集问题
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 50000005;
typedef long long ll;
int n;
ll f[N];
ll solution(int n) {
    ll sum = 1;
    if(f[n]) return f[n];
    for(int i = 1; i <= n/2; ++i) {
        sum += solution(i);
    }
    f[n] = sum;
    return sum;
}
int main() {

    cin >> n;
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    cout << solution(n) << endl;
    // 结束计时
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    cout << "time: " << duration.count() << " ms" << endl;
    return 0;
}