#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

vector<int> x_ = {0, 0, 1, -1};
vector<int> y_ = {1, -1, 0, 0};
vector<vector<int>> grid;
vector<vector<int>> neighbor;

vector<int> add_cow(int x, int y) {
    vector<int> v;
    for (int i = 0; i < 4; i++) {
        int x1 = x + x_[i];
        int y1 = y + y_[i];
        if (!grid[x1][y1]) v = {x1, y1};
    }
    return v;
}

signed main() {
    IOS;

    int n; cin >> n;

    grid.resize(2e3, vector<int>(2e3, 0));
    neighbor.resize(2e3, vector<int>(2e3, 0));

    int cows = 0, buffer = 10;
    while (n--) {
        int x, y; cin >> x >> y;
        x += buffer, y += buffer;
        if (grid[x][y]) {
            cows--;
            cout << cows << endl;
            continue;
        }

        grid[x][y]++;
        for (int i = 0; i < 4; i++) neighbor[x + x_[i]][y + y_[i]]++;

        queue<vector<int>> bfs;
        bfs.push({x, y});
        while (!bfs.empty()) {
            auto data = bfs.front(); bfs.pop();
            int x1 = data[0], y1 = data[1];
            for (int i = 0; i < 4; i++) {
                int x2 = x1 + x_[i];
                int y2 = y1 + y_[i];
                if (neighbor[x2][y2] == 3) {
                    auto data2 = add_cow(x2, y2);
                    int x3 = data2[0], y3 = data2[1];
                    grid[x3][y3]++;
                    for (int j = 0; j < 4; j++) neighbor[x3 + x_[j]][y3 + y_[j]]++;
                    bfs.push({x3, y3});
                    cows++;
                }
            }
        }

        cout << cows << endl;
    }
}