#include<bits/stdc++.h>
#define endl '\n'
typedef unsigned long long ull;
const int N = 105;
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
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    StirlingNumbers();
    ofs << BellNumber(n);
    ifs.close();
    ofs.close();
    return 0;
}
