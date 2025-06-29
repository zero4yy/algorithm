// 实现题 2-7 集合划分问题
#include<bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
const int N = 10005;
using namespace std;
ull S[N][N];
int n;
void StirlingNumbers() {
    S[0][0] = 1; //s(0, 0) = 1
    for(int i = 1; i <= n; ++i) {
        for(int k = 1; k <= n; k++) {
            S[i][k] = k * S[i - 1][k] + S[i - 1][k - 1];
        }
    }
}
ull BellNumber(int n) {
    ull number = 0;
    for(int k = 1; k <= n; ++k) number += S[n][k]; //计算bell数
    return number;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ifstream ifs("testData/input3.txt");
    ofstream ofs("results/output3.txt");
    ifs >> n;
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    StirlingNumbers();
    ofs << BellNumber(n) << endl;
    // 结束计时
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    ofs << "time: " << duration.count() << " ms" << endl;
    ifs.close();
    ofs.close();
    return 0;
}
