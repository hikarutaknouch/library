#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
map<T, T> primeFactor(T n) {
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
    return 0;
}