#include <bits/stdc++.h>

using namespace std;
// a/b + c/d = (a*d+b*c)/b*d
int a, b, c, d;
int fm, fz;
int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;    
}

int lcm (int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int main() {
    cin >> a >> b >> c >> d;
    fm = lcm(b, d), fz = a * lcm(b,d) / b + c * lcm(b,d) / d;
    int ggcd = gcd(fm, fz);
    fm /= ggcd;
    fz /= ggcd;
    cout << fz << '/' << fm << endl;
    return 0;
}