#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef long long ll;
int n;
ll f[N];
void solution(int n) {
    ll sum = 1;
    if(f[n]) return;
    for(int i = 1; i <= n/2; ++i) {
        solution(i);
        sum += f[i];
    }
    f[n] = sum;
    return;
}
int main() {
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    solution(n);
    cout << f[n];
    ofs << f[n];
    ifs.close();
    ofs.close();
    return 0;
}