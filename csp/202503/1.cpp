#include <iostream>

using namespace std;

int b, c, l, r;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> b >> c >> l >> r;
    int ans = 0;
    if(l % 2 == 1) l ++;
    for(int i = l; i <= r; i += 2) {
        ans += (i * i + b * i + c);
    }
    ans *= 2;

    cout << ans;

    return 0;
}