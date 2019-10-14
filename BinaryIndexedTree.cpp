#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree {
    vector<T> data;
    int n;
    BinaryIndexedTree(int n, T d) : n(n), data(n+1,d) {}
    T sum(int i) {
        T res = 0;
        for(int x = i; x>0; x-=(x&-x)) res += data[x];
        return res;
    }
    void add(int i, T v) {
        for(int x = i; x<=n; x+=x&-x) data[x] += v;
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