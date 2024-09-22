#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

vector<int> x_ = {0, 0, 1, -1};
vector<int> y_ = {1, -1, 0, 0};

signed main() {
    IOS;

    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<vector<vector<int>>>> switches(n + 1, vector<vector<vector<int>>>(n + 1));
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

    int ans = 1;
    set<vector<int>> neighbors;

    queue<vector<int>> q;
    vector<vector<int>> light(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
    q.push({1, 1});
    light[1][1]++;
    visited[1][1]++;
    
    while (!q.empty()) {
        vector<vector<int>> nlights;
        while (!q.empty()) {
            auto data = q.front(); q.pop();
            int x = data[0], y = data[1];

            for (auto l: switches[x][y]) nlights.push_back(l);
            
            for (int i = 0; i < 4; i++) {
                int x1 = x + x_[i];
                int y1 = y + y_[i];
                if (x1 <= 0 || x1 > n || y1 <= 0 || y1 > n) continue;
                if (visited[x1][y1]) continue;
                //cout << "passed: " << x1 << " " << y1 << endl;
                if (light[x1][y1]) {
                    //cout << "pushed: " << x1 << " " << y1 << endl;
                    q.push({x1, y1});
                    visited[x1][y1]++;
                }
                else {
                    //cout << "neighbor: " << x1 << " " << y1 << endl;
                    neighbors.insert({x1, y1});
                }
            }
        }

        for (auto l: nlights) {
            int x = l[0], y = l[1];
            if (!light[x][y]) {
                light[x][y]++;
                ans++;
                auto it = neighbors.find({x, y});
                if (it != neighbors.end()) {
                    //cout << x << " " << y << endl;
                    q.push({x, y});
                    visited[x][y]++;
                    neighbors.erase(it);
                }
            }
        }
        //cout << endl;
    }

    cout << ans << endl;
}