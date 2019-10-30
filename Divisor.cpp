#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> Divisor(T x) {
    vector<T> res;
    for(T i = 1; i*i<=x; ++i) {
        if(x%i==0) {
            res.emplace_back(i);
            if(i*i!=x) res.emplace_back(x/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    vector<int> v = Divisor(n);
    return 0;
}