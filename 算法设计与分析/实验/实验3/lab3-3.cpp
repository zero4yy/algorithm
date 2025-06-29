#include <iostream>
#include <string>
#define endl '\n'
using namespace std;
string A, B;
int k;
int StrComp() {
    int len1 = A.length();
    int len2 = B.length();
    int dp[len1 + 1][len2 + 1];
    
    for(int i = 0; i <= len1; i++) dp[i][0] = i * k;
    for(int i = 0; i <= len2; i++) dp[0][i] = i * k;
    dp[0][0] = 0;

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + abs(A[i - 1] - B[j - 1]), min(dp[i][j - 1] + k, dp[i - 1][j] + k));
        }
    }

    return dp[len1][len2];
}
int main() {
    cin >> A >> B >> k;
    cout << StrComp();
    return 0;
}