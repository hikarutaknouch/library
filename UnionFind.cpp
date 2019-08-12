#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPP(i, n) for(int i = 1; i <= n; ++i)
#define REPR(i, n) for(int i = n-1; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1000000007;
const ll INF = 1000000000;

struct UnionFind {
    vector<int> par, size;
    UnionFind(int n) : par(n), size(n) {
        for(int i = 0; i < n; ++i) par[i] = i;
        size.assign(n,1);
    }
    void Union(int x, int y) {
        x = Find(x), y = Find(y);
        if(x == y) return;
        if(size[x] < size[y]) swap(x,y);
        size[x] += size[y];
        par[y] = x;
    }
    int Find(int x) {
        if(par[x]==x) return x;
        else return par[x] = Find(par[x]);
    }
    bool Same(int x, int y) {
        return Find(x) == Find(y);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    UnionFind uf(n);
    return 0;
}