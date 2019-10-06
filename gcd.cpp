#include <bits/stdc++.h>
using namespace std;

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