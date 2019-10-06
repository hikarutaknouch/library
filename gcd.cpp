#include <bits/stdc++.h>
using namespace std;

template<typename T>
T GCD(T x, T y) {
    if(x<y) gcd(y,x);
    while(y>0) {
        T tmp = x%y;
        x = y;
        y = tmp;
    }
    return x;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y; cin >> x >> y;
    int n = GCD(x,y);
    return 0;
}