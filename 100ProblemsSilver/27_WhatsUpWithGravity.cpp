#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<int> x_ = {1, -1, 0};
vector<int> y_ = {1, -1};
vector<int> g_ = {0, 0, 1};

signed main() {
    IOS;

    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int sx, sy;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] == 'C') {
                sx = j;
                sy = i;
            }
        }
    }

    int ans = 1e6;
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, 1e6))); 

    queue<vector<int>> bfs; // x, y, gravity
    bfs.push({sx, sy, 0});
    visited[sy][sx][0] = 0;
    while (!bfs.empty()) {
        auto data = bfs.front(); bfs.pop();
        int x = data[0], y = data[1], g = data[2];
        if (grid[y][x] == 'D') {
            ans = min(g, ans);
            continue;
        }
        int y1 = y + y_[g % 2];
        if (y1 < 0 || y1 >= n) continue;
        if (visited[y1][x][g % 2] <= g || g >= ans) continue;
        if (grid[y1][x] != '#') {
            bfs.push({x, y1, g});
            visited[y1][x][g % 2] = g;
            continue;
        }

        for (int i = 0; i < 3; i++) {
            int x1 = x + x_[i];
            int g1 = g + g_[i];
            if (x1 < 0 || x1 >= m || grid[y][x1] == '#') continue;
            if (visited[y][x1][g1 % 2] <= g1 || g1 >= ans) continue;
            bfs.push({x1, y, g1});
            visited[y][x1][g1 % 2] = g1;
        }
    }

    if (ans == 1e6) cout << -1 << endl;
    else cout << ans << endl;
}