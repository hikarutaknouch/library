#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPP(i, n) for(int i = 1; i <= n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1000000007;
const ll INF = 1000000000;

ll gcd(ll x, ll y) {
    if(x<y) gcd(y,x);
    while(y>0) {
        ll tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}

int main() {
    ll x,y; cin >> x >> y;
    cout << gcd(x,y) << endl;
    return 0;
}