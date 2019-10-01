#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree {
    vector<T> data;
    int n;
    BinaryIndexedTree(int n, T x) : n(n), data(n+1,x) {}
    T sum(int i) {
        T res = 0;
        for(++i; i>0; i -= (i&-i)) res += data[i];
        return res;
    }
    void add(int i, T x) {
        for(++i; i <= n; i += i&-i) data[i] += x;
    }
    int lower_bound(int k) {
        if(k <= 0) return 0;
        int res = 0, i = 1;
        while(i<n) i *= 2;
        for(; i>0; i/=2) {
            if(res+i <= n && data[res+i] < k) {
                k -= data[res+i];
                res += i;
            }
        }
        return res + 1;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    BinaryIndexedTree<int> bit(n,0);
    return 0;
}