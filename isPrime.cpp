#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool isPrime(T x) {
    for(T i = 2; i*i <= x; ++i) {
        if(!x%i) return false;
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