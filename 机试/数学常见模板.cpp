// 快速幂 m^k mod p, O(logk)
int qmi(int m, int k, int p) {
    int res = 1 % p, t = m;
    while(k) {
        if(k & 1) res = res * t % p;
        t = t * t %  p;
        k >>= 1;
    }
    return res;
}

//最大公约数 gcd
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

//最小公倍数 lcm
int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}