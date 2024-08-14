#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

vector<int> x_ = {0, 0, 1, -1};
vector<int> y_ = {1, -1, 0, 0};

signed main() {
    IOS;

    int n; cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n ; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') grid[i][j] = 1;
        }
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));

    int maxa = 0, minp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] || !grid[i][j]) continue;

            queue<vector<int>> bfs;

            bfs.push({i, j});
            visited[i][j]++;

            int a = 0, p = 0;
            while (!bfs.empty()) {
                auto data = bfs.front(); bfs.pop();
                int x = data[0], y = data[1];
                a++;

                for (int i = 0; i < 4; i++) {
                    int x1 = x + x_[i];
                    int y1 = y + y_[i];
                    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || !grid[x1][y1]) {
                        p++;
                        continue;
                    }
                    if (visited[x1][y1]) continue;
                    visited[x1][y1] = 1;
                    bfs.push({x1, y1});
                }
            }

            if (a > maxa) {
                maxa = a;
                minp = p;
            }
            else if (a == maxa) minp = min(p, minp);
        }
    }

    cout << maxa << " " << minp << endl;
}