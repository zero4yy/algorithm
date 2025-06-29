#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
 
double F(double a, double x) {
    double a2 = a * a, x2 = x * x;
    return (x * sqrt(a2 + x2) + a2 * log(fabs(x + sqrt(a2 + x2)))) / 2;
}
 
double cal_length(double w, double h) {
    double a = 4.0 * h / (w * w);
    double b = 1.0 / (2 * a);
    return (F(b, w/2) - F(b, 0)) * 4 * a;
}
 
int main() {
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        int D, B, H, L;        
        scanf("%d%d%d%d", &D, &H, &B, &L);
 
        int n = (B + D - 1) / D;
        double D1 = (double) B / n;
        double L1 = (double) L / n;
 
        double x = 0, y = H;
        while (y - x > 1e-5) {
            double m = x + (y - x) / 2;
            if (cal_length(D1, m) < L1)
                x = m;
            else y = m;
        }
 
        if (cas > 1) printf("\n");
        printf("Case %d:\n%.2lf\n", cas++, H-x);
    }
    return 0;
}