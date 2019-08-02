#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string lcs(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    REP(i,n) {
        REP(j,m) {
            if(s[i]==t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    string ans = "";
    int x = n; int y = m;
    while(x>0 && y>0) {
        if(dp[x][y] == dp[x-1][y]) x--;
        else if(dp[x][y] == dp[x][y-1]) y--;
        else {
            x --; y--;
            ans += s[x];
        }
    }
    reverse(ALL(ans));
    return ans;
}

int main() {
    string s,t; cin >> s >> t;
    cout << lcs(s,t) << endl;
    return 0;
}
