#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

vector<int> x_ = {0, 0, 1, -1};
vector<int> y_ = {1, -1, 0, 0};
string dir = "RLDU";

signed main() {
    IOS;

    int n, m; cin >> n >> m;

    int sx, sy;
    queue<vector<int>> q;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    vector<vector<int>> mvisit(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            char c = s[j];
            if (c == '#') maze[i][j]++;
            if (c == 'M') {
                q.push({i, j, 0});
                mvisit[i][j]++;
            }
            if (c == 'A') sx = i, sy = j;
        }
    }

    vector<vector<int>> mdist(n, vector<int>(m, 1e8));
    while (!q.empty()) {
        auto data = q.front(); q.pop();
        int x = data[0], y = data[1], d = data[2];

        mdist[x][y] = d;

        for (int i = 0; i < 4; i++) {
            int x1 = x + x_[i];
            int y1 = y + y_[i];

            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || mvisit[x1][y1] || maze[x1][y1]) continue;
            q.push({x1, y1, d + 1});
            mvisit[x1][y1]++;
        }
    }

    int ex = -1, ey;
    map<vector<int>, char> parent;
    vector<vector<int>> visit(n, vector<int>(m, 0));

    q.push({sx, sy, 0});
    visit[sx][sy]++;
    parent[{sx, sy}] = 'A';

    while (!q.empty()) {
        auto data = q.front(); q.pop();
        int x = data[0], y = data[1], d = data[2];

        if (mdist[x][y] <= d) continue;

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            ex = x;
            ey = y;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int x1 = x + x_[i];
            int y1 = y + y_[i];

            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || visit[x1][y1] || maze[x1][y1]) continue;
            q.push({x1, y1, d + 1});
            visit[x1][y1]++;
            parent[{x1, y1}] = dir[i];
        }
    }

    if (ex == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        string ans = "";
        while (true) {
            char c = parent[{ex, ey}];
            if (c == 'A') break;
            ans += c;
            if (c == 'L') ey++;
            if (c == 'R') ey--;
            if (c == 'U') ex++;
            if (c == 'D') ex--;
        }
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    }
}