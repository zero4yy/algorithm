#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N]; // s 表示某一个数出现的次数
int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    int res = 0;
    for(int i = 0, j = 0; i < n; i ++) {
        s[a[i]] ++;
        while(s[a[i]] > 1) {
            s[a[j]] --;
            j ++;
        }

        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}