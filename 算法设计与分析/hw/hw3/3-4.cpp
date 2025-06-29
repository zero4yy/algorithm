#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);  
    int n;
    cin >> n;
    int **a =  new int* [n];
    int **dp =  new int* [n];
    
    for(int i = 0; i < n; ++i) {
        a[i] = new int [i + 1];
        dp[i] = new int [i + 1];
    }

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) 
        dp[n - 1][i] = a[n - 1][i];
    
    for(int  i = n-2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]) + a[i][j];
        }
    }

    cout << dp[0][0];
}