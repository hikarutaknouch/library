#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lis(int n, vector<int>& v) {
    vector<int> dp(n+1, 0);
    dp[0] = v[0];
    int length = 1;
    for(int i = 1; i <= n-1; ++ i) {
        if(dp[length-1]<v[i]) dp[length++] = v[i];
        else *lower_bound(dp.begin(), dp.begin()+length, v[i]) = v[i];
    }
    return length;
}

int main() {
    int n;
    vector<int> a(n);
    lis(n,a);
    return 0;
}