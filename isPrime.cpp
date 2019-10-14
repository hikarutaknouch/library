#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool isPrime(T x) {
    if(x==1) return false;
    for(T i = 2; i*i <= x; ++i) {
        if(x%i==0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    bool res = isPrime(n);
    return 0;
}