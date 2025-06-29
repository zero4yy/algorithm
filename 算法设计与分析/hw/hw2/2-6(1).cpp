#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
const int N = 100;
using namespace std;
int n;
ll factorial[N];
int perm[N];
void calcu_factorial(int n) {
    factorial[1] = 1;
    for(int i = 2; i <= n; i++) {
        factorial[i] = i * factorial[i - 1];
    }
    return;
}
ll Order() {
    ll order = 0;
    vector<int> elems;
    for(int i = 1; i <= n; ++i) elems.push_back(i);

    for(int i = 0; i < n; ++i) {
        int pos = find(elems.begin(), elems.end(), perm[i]) - elems.begin(); 
        order += pos * factorial[n - i - 1];
        elems.erase(elems.begin() + pos);
    }
    
    return order;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    for(int i = 0; i < n; ++i) ifs >> perm[i];

    calcu_factorial(n);

    ofs << Order() << endl;

    //计算下一个字典序排列
    next_permutation(perm, perm + n);

    for(int i = 0; i < n; ++i) ofs << perm[i] << ' ';

    ifs.close();
    ofs.close();
    return 0;
}
