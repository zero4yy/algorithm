// https://atcoder.jp/contests/abc366/tasks/abc366_d
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct Pre3D {
    
    int n, m, h;
    vector<vector<vector<int>>> sum;    // 下标从0开始

    Pre3D(int n, int m, int h) {
        this->n = n;
        this->m = m;
        this->h = h;
        sum = vector<vector<vector<int>>> (n + 1, vector<vector<int>> (m + 1, vector<int> (h + 1)));
    }

    void prefix() {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= h; k++) {
                    sum[i][j][k] += sum[i][j][k - 1];
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k <= h; k++) {
                    sum[i][j][k] += sum[i][j - 1][k];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= h; k++) {
                    sum[i][j][k] += sum[i - 1][j][k];
                }
            }
        }
    }

    int query(int x1, int y1, int z1, int x2, int y2, int z2) { // 查询区间(x1, y1, z1)~(x2, y2, z2)的和, x1 <= x2 && y1 <= y2 && z1 <= z2
        int a = sum[x2][y2][z2];
        int b = x1 > 0 ? sum[x1 - 1][y2][z2] : 0;
        int c = y1 > 0 ? sum[x2][y1 - 1][z2] : 0;
        int d = z1 > 0 ? sum[x2][y2][z1 - 1] : 0;
        int e = x1 > 0 && y1 > 0 ? sum[x1 - 1][y1 - 1][z2] : 0;
        int f = x1 > 0 && z1 > 0 ? sum[x1 - 1][y2][z1 - 1] : 0;
        int g = y1 > 0 && z1 > 0 ? sum[x2][y1 - 1][z1 - 1] : 0;
        int h = x1 > 0 && y1 > 0 && z1 > 0 ? sum[x1 - 1][y1 - 1][z1 - 1] : 0;
        return a - b - c - d + e + f + g - h;
    }

};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    Pre3D P(n, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> P.sum[i][j][k];
            }
        }
    }
    P.prefix();
    int q;
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        x1--; x2--; y1--; y2--; z1--; z2--;
        cout << P.query(x1, y1, z1, x2, y2, z2) << endl;
    }
    return 0;
}
