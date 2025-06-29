#include<bits/stdc++.h>
#include<math.h>
typedef long long ll;
const int N = 1e5 + 1;
using namespace std;
int n, m, flag, i, j;
double k[N], theta[N], x, y, x_, y_;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    for(i = 0; i < N; i++) k[i] = 1.0;
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        double a;
        cin >> flag >> a;
        if(flag == 1) {
            k[i] = k[i - 1] * a;
            theta[i] = theta[i - 1];
        }
        else {
            k[i] = k[i - 1];
            theta[i] = theta[i - 1] + a;
        }
    }

    while(m--) {
        cin >> i >> j >> x_ >> y_;
        double _k = k[j] / k[i - 1];
        double _theta = theta[j] - theta[i - 1];
        x = _k * (x_ * cos(_theta) - y_ * sin(_theta));
        y = _k * (x_ * sin(_theta) + y_ * cos(_theta));
        printf("%lf %lf\n", x, y);
    }
    return 0;
}