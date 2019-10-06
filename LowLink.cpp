#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;

struct LowLink {
    vector<pair<int,int>> bridge;
    vector<int> ord,low,articulation;
    vector<bool> used;
    vector<vector<int>> g;
    int n, k = 0;
    LowLink(const vector<vector<int>> &g) : g(g) {
        n = g.size();
        ord.resize(n, -1);
        low.resize(n, -1);
        used.resize(n, false);
    }
    void dfs(int v, int pre) {
        used[v] = true;
        ord[v] = k++;
        low[v] = ord[v];
        bool isArticulation = false;
        int cnt = 0;
        for(auto &to : g[v]) if(to != pre) {
            if(!used[to]) {
                cnt ++;
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if(low[to]>ord[v]) {
                    bridge.emplace_back(min(v,to), max(v,to));
                }
                if(pre != -1 && low[to]>=ord[v]) {
                    isArticulation = true;
                }
            }
            else {
                low[v] = min(low[v], ord[to]);
            }
        }
        if(pre == -1 && cnt>1) isArticulation = true;
        if(isArticulation) articulation.push_back(v);
    }
};

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> g(n);
    REP(i,m) {
        int a,b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    LowLink ans(g);
    ans.dfs(0,-1);
    cout << ans.articulation.size() << endl;
    cout << ans.bridge.size() << endl;
    return 0;
}