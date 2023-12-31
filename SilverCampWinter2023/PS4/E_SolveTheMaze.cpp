#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

vector<int> x_ = {-1, 1, 0, 0};
vector<int> y_ = {0, 0, -1, 1};

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> wall(n, vector<int>(m, 0));

        vector<pair<int,int>> good, bad;

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '#') wall[i][j] = 1;
                else if (s[j] == 'G') {
                    good.push_back({i, j});
                    wall[i][j] = 2;
                }
                else if (s[j] == 'B') {
                    bad.push_back({i, j});
                    wall[i][j] = 3;
                }
            }
        }

        for (auto data: bad) {
            int i = data.f, j = data.s;

            for (int k = 0; k < 4; k++) {
                int x = i + x_[k], y = j + y_[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;

                if (wall[x][y] == 0) {
                    wall[x][y] = 1;
                }
            }
        }

        bool metBad = false;

        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> bfs;
        if (wall[n-1][m-1] != 1) bfs.push({n-1, m-1});
        while (!bfs.empty()) {
            auto d = bfs.front(); bfs.pop();
            int i = d.f, j = d.s;


            if (visited[i][j]) continue;
            visited[i][j] = 1;
            
            if (wall[i][j] == 2) {
                ans++;
            }

            for (int k = 0; k < 4; k++) {
                int x = i + x_[k], y = j + y_[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (wall[x][y] == 0 || wall[x][y] == 2) bfs.push({x, y});
                else if (wall[x][y] == 3) metBad = true;
            }
        }

        //cout << "ans: " << ans << endl;
        //cout << "goodsize: " << good.size() << endl;
        if (metBad || ans != good.size()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}