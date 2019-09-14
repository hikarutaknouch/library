#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int INF = pow(2,31)-1;

template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    vector<Monoid> data;
    int n;
    const F f;
    const Monoid M;
    SegmentTree(int x, const F f, const Monoid &M) : f(f), M(M) {
        n = 1;
        while(n<x) n <<= 1;
        data.resize(2*n,M);
    }
    void set(int k, const Monoid &p) {
        data[k+n] = p;
    }
    void build() {
        for(int k = n-1; k > 0; --k) {
            data[k] = f(data[2*k + 0], data[2*k + 1]);
        }
    }
    void update(int k, const Monoid &p) {
        k += n;
        data[k] = p;
        while (k >>= 1) {
            data[k] = f(data[k*2 + 0], data[k*2 + 1]);
        }
    }
    Monoid query(int a, int b) {
        Monoid L = M, R = M;
        for(a += n, b += n; a<b; a >>= 1, b >>= 1) {
            if(a&1) L = f(L, data[a++]);
            if(b&1) R = f(data[--b], R);
        }
        return f(L,R);
    }
    Monoid operator[](const int &k) const {
        return data[k+n];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    SegmentTree<int> seg(n, [](int a,int b){return min(a,b);}, INF);
    int ans;
    REP(i,q) {
        int c,x,y; cin >> c >> x >> y;
        if(c==0) seg.update(x,y);
        else {
            ans = seg.query(x,y+1);
            cout << ans << endl;
        }
    }
    return 0;
}