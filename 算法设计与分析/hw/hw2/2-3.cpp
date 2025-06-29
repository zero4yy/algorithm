#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef long long ll;
int n;
ll f[N];
int solution(int n) {
    ll sum = 1;
    if(f[n]) return f[n];
    for(int i = 1; i <= n/2; ++i) {
        sum += solution(i);
    }
    f[n] = sum;
    return sum;
}
int main() {
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    cout << solution(n);
    ofs << solution(n);
    ifs.close();
    ofs.close();
    return 0;
}