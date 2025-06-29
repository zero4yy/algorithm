#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int uniquePaths(int m, int n) {
        // 数学方法 pascal 求组合数c[m][n] = c[m-1][n-1] + c[m-1][n]
        // 二维
        m --, n--;
        int sum = m + n;
        n = min(m, n);
        vector<vector<long long> > C(sum + 1, vector<long long> (n + 1, 0));
        C[0][0] = 1;
        for(int i = 1; i <= sum; i ++) {
            for(int j = 1; j <= min(i, n); j ++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            } 
        }
        return C[sum][n];

        
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        // 数学方法 将二维优化为一维
        m --, n--;
        int sum = m + n;
        n = min(m, n);
        // vector<vector<long long> > C(sum + 1, vector<long long> (n + 1, 0));
        vector<long long> C(n + 1);
        C[0] = 1;
        for(int i = 1; i <= sum; i ++) {
            for(int j = min(i, n); j >= 1; j --) {
                C[j] = C[j - 1] + C[j];
            } 
        }
        return C[n];
    }
};


// 根据题目推导
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long> > C(m + 1, vector<long long> (n + 1, 0));
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                C[i][j] = C[i][j - 1] + C[i - 1][j];
            }
        }
        return C[m][n];
    }
};

int main() {
    

    return 0;
}