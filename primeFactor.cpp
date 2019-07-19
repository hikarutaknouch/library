#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> primeFactor(ll N) {
    map<ll,ll> res;
    for(ll i = 2; i*i<=N; ++i) {
        while(N%i==0) {
            res[i] ++;
            N /= i;
        }
    }
    if(N != 1) res[N] = 1;
    return res;
}

int main() {
    return 0;
}