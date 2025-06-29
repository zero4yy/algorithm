int mod = 1e9 + 7;

struct mint {
    int x;

    mint() : x(0) {}

    mint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    mint &operator+=(const mint &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    mint &operator/=(const mint &p) {
        *this *= p.inverse();
        return *this;
    }

    mint operator-() const { return mint(-x); }
    mint operator+() const { return mint(*this); }

    mint operator+(const mint &p) const { return mint(*this) += p; }

    mint operator-(const mint &p) const { return mint(*this) -= p; }

    mint operator*(const mint &p) const { return mint(*this) *= p; }

    mint operator/(const mint &p) const { return mint(*this) /= p; }

    bool operator==(const mint &p) const { return x == p.x; }

    bool operator!=(const mint &p) const { return x != p.x; }

    mint inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
        t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
        }
        return mint(u);
    }

    mint pow(int64_t n) const {
        mint ret(1), mul(x);
        while (n > 0) {
        if (n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const mint &p) { return os << p.x; }

    friend istream &operator>>(istream &is, mint &a) {
        int64_t t;
        is >> t;
        a = mint(t);
        return (is);
    }

    int get() const { return x; }

};

vector<mint> fact(1, 1);
vector<mint> inv_fact(1, 1);
 
mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    while ((int) fact.size() < n + 1) {
        fact.push_back(fact.back() * (int) fact.size());
        inv_fact.push_back(mint(1) / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}