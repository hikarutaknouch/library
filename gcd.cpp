#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPP(i, n) for(int i = 1; i <= n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

template<typename T>
T gcd(T x, T y) {
    if(x<y) gcd(y,x);
    while(y>0) {
        T tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}

int main() {
    int x,y; cin >> x >> y;
    cout << gcd(x,y) << endl;
    return 0;
}