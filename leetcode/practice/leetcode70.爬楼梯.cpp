#include <iostream>

using namespace std;

class Solution {
public:
    int f[50];
    int climbStairs(int n) {
    // f[n] = f[n-1] + f[n-2]
    f[1] = 1, f[2] = 2;
    for(int i = 3; i <= n; i ++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
    }
};

int main() {
	
	return 0;
}