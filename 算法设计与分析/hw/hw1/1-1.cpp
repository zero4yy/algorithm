//暴力解法
#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
ll a[10];
int n;
void func(ll y) {
    while(y) a[y % 10]++, y /= 10;
}
int main() {
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    for(ll i = 1; i <= n; i++) {
        func(i);
    }
    for(int i = 0 ; i <= 9; i++) ofs << a[i] << endl;
    
    ifs.close();
    ofs.close();

    return 0;
}