#include <iostream>

using namespace std;

const int N = 100010;

int n, m, x;
int A[N], B[N];
int main() {
    cin >> n >> m >> x;
    for(int i = 0; i < n; i ++) cin >> A[i];
    for(int i = 0; i < m; i ++) cin >> B[i];


    int i = 0, j = m - 1;
    while(i < n && j >= 0) {
        if(A[i] + B[j] == x) {
            cout << i << ' ' << j << endl;
            break;
        }
        
        else if(A[i] + B[j] > x) j --;
        else i++;
    }
    return 0;
}