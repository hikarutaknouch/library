#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

template<int MOD>
struct ModInt {
    using M = ModInt;
    long long val;
    ModInt(long long v = 0) {
        set_val(v % MOD + MOD);
    }
    M& set_val(unsigned int v) {
        val = v<MOD ? v : v - MOD;
        return *this;
    }
    explicit operator bool() const {return val != 0;}
    M operator-() const {return M() - *this;}
    M operator+(const M& r) const {return M().set_val(val + r.val);}
    M operator-(const M& r) const {return M().set_val(val + MOD - r.val);}
    M operator*(const M& r) const {return M().set_val((long long) val * r.val % MOD);}
    M operator/(const M& r) const {return *this * r.inverse();}
    M& operator+=(const M& r) {return *this = *this + r;}
    M& operator-=(const M& r) {return *this = *this - r;}
    M& operator*=(const M& r) {return *this = *this * r;}
    M& operator/=(const M& r) {return *this = *this / r;}
    bool operator==(const M& r) const {return val == r.val;}
    M pow(long long n) const {
        M x = *this, r = 1;
        while(n>0) {
            if(n & 1) r *= x;
            x *= x;
            n >> 1;
        }
        return r;
    }
    M inverse() const {
        int a = val, b = MOD, u = 1, v = 0, t;
        while(b>0) {
            t = a/b;
            swap(a-=t*b, b);
            swap(u-=t*v, v);
        }
        return ModInt(u);
    }
    friend istream& operator<<(istream& i, const M& r) {
        long long tmp; i >> tmp;
        r = M(i);
        return i;
    }
    friend ostream& operator<<(ostream& os, const M& r) {
        return os << r.val;
    }
};

template<typename M>
struct BinomialCoefficients {
    vector<M> fact, finv, inv;
    BinomialCoefficients() {};
    BinomialCoefficients(int n) : fact(n+1), finv(n+1), inv(n+1) {
        init(n);
    }
    void init(int n) {
        fact[0] = finv[n] = inv[0] = 1;
        for(int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;
        finv[n] /= fact[n];
        for(int i = n-1; i >= 0; --i) finv[i] = finv[i+1] * (i+1);
        for(int i = 1; i<= n; ++i) inv[i] = finv[i]*fact[i-1];
    }
    M C(int n, int k) {
        if(n<k || k<0) return 0;
        return fact[n]*finv[n-k]*finv[k];
    }
    M P(int n, int k) {
        if(n<k || k<0) return 0;
        return fact[n]*finv[n-k];
    }
    M H(int n, int k) {
        if(n<0 || k<0) return 0;
        return k == 0 ? 1 : C(n+k-1,k);
    }
};

using mint = ModInt<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    BinomialCoefficients<mint> bc(n);
    return 0;
}