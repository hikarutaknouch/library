#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree2D {
    vector<vector<T>> data;
    int n,m;
    T d;
    BinaryIndexedTree2D(int n,int m, T d) : n(n), m(m), d(d), data(n+1,vector<T>(m+1,d)) {}
    T sum(int i, int j) {
        T res = d;
        for(int x = i; x>0; x-=x&-x) {
            for(int y = j; y>0; y-=y&-y)) {
                res += data[x][y];
            }
        }
        return res;
    }
    void add(int i, int j, T v) {
        for(int x = i; x<=n; x+=x&-x) {
            for(int y = j; y<=m; y+=y&-y) {
                data[x][y] += v;
            }
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    BinaryIndexedTree2D<int> bit(n,m,0);
    return 0;
}