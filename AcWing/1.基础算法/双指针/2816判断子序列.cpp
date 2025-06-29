#include <iostream>

using namespace std;

const int N = 10010;

int n, m, a[N], b[N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];

    int i = 0, j = 0;

    int flag = 0;
    for(int i = 0, j = 0; i < n; i ++) {
        while(j < m && a[i] != b[j]) j ++;
    }

    if(i == n - 1)
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            if(i == n - 1) {flag = 1; break;}
            i++, j++;
        }
        else j++;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
}