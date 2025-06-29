#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace  std;

/*


*/
class Solution {
public:
    int f[10005];
    int numSquares(int n) {
        int x = (int)sqrt(n);
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j * j <= i; j ++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }
        return f[n];
    }
};

int main() {
    int n; cin >> n;
    Solution sl;
    cout << sl.numSquares(n);
    return 0;
}