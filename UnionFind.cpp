#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPP(i, n) for(int i = 1; i <= n; ++i)
#define REPR(i, n) for(int i = n-1; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct UnionFind {
    vector<int> par, size;
    UnionFind(int n) : par(n), size(n,1) {
        for(int i = 0; i < n; ++i) par[i] = i;
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
    int Size(int x) {
        return size[Find(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    UnionFind uf(n);
    return 0;
}