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
    vector<int> data;
    void init(int n) {
        data.assign(n,-1);
    }
    void Union(int x, int y) {
        x = Find(x), y = Find(y);
        if(x == y) return;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }
    int Find(int x) {
        if(data[x]<0) return x;
        else return data[x] = Find(data[x]);
    }
    bool same(int x, int y) {
        return Find(x) == Find(y);
    }
    int size(int x) {
        return -data[Find(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    return 0;
}