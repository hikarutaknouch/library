#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
map<T, T> PrimeFactor(T n) {
    map<T,T> res;
    for(T i = 2; i*i<=n; ++i) {
        while(n%i==0) {
            res[i] ++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    map<int,int> m = PrimeFactor(n);
    return 0;
}