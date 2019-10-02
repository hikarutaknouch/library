#include <bits/stdc++.h>
using namespace std;

static const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    int sy,sx,gy,gx; cin >> sy >> sx >> gy >> gx; --sx,--sy,--gx,--gy;
    vector<string> grid(h);
    for(int i = 0; i < h; ++i) cin >> grid[i];
    vector<vector<int>> used(h, vector<int>(w,-1));
    using P = pair<int,int>;
    queue<P> que;
    que.push({sy,sx});
    used[sy][sx] = 0;
    while(!que.empty()) {
        P cur = que.front(); que.pop();
        for(int d = 0; d < 4; ++ d) {
            int x = cur.second + dx[d], y = cur.first + dy[d];
            if(x<0 || x>=w || y<0 || y>=h) continue;
            if(used[y][x]!=-1 || grid[y][x]=='#') continue;
            used[y][x] = used[cur.first][cur.second]+1;
            que.push({y,x});
        }
    }
    cout << used[gy][gx] << endl;
    return 0;
}