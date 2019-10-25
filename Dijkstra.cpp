#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct edge {
    int to;
    T cost;
    bool operator > (const edge &r) const { return cost > r.cost; }
};

template<typename T>
vector<T> Dijkstra(int s, const vector<vector<edge<T>>> &g) {
    int n = g.size();
    const T INF = numeric_limits<T>::max();
    using E = edge<T>;
    vector<T> dist(n,INF);
    priority_queue<E, vector<E>, greater<E>> que;
    dist[s] = 0;
    que.push({s,0});
    while(!que.empty()) {
        E now = que.top(); que.pop();
        if(dist[now.to] < now.cost) continue;
        for(auto next : g[now.to]) {
            if(dist[next.to] > dist[now.to] + next.cost) {
                dist[next.to] = dist[now.to] + next.cost;
                que.push({next.to, dist[next.to]});
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v,e,r; cin >> v >> e >> r;
    vector<vector<edge<ll>>> g(v);
    for(int i = 0; i < e; ++i) {
        ll s,t, d; cin >> s >> t >> d;
        g[s].push_back({(int)t,d});
    }
    vector<ll> dist = Dijkstra(r,g);
    for(int i = 0; i < v; ++i) {
        ll ans = dist[i];
        if(ans>=numeric_limits<ll>::max()) cout << "INF" <<'\n';
        else cout << ans << '\n';
    }
    return 0;
}