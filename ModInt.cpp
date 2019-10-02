#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;

template<int MOD>
struct ModInt {
    using M = ModInt;
    long long val;
    ModInt(long long v = 0) {set_val(v%MOD+MOD);}
    M& set_val(unsigned int v) {
        val = v<MOD ? v : v - MOD;
        return *this;
    }
    M operator-() const {return M() - *this;}
    M operator+(const M& r) const {return M().set_val(val+r.val);}
    M operator-(const M& r) const {return M().set_val(val+MOD-r.val);}
    M operator*(const M& r) const {return M().set_val(val*r.val%MOD);}
    M operator/(const M& r) const {return *this * r.inverse();}
    M& operator+=(const M& r) {return *this = *this+r;}
    M& operator-=(const M& r) {return *this = *this-r;}
    M& operator*=(const M& r) {return *this = *this*r;}
    M& operator/=(const M& r) {return *this = *this/r;}
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

const int MOD = 1000000007;
using mint = ModInt<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}