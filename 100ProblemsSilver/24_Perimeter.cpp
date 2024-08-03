/*
Solution:
BFS through haybales and add perimeter tiles to set,
then BFS through perimeter tiles, compute perimeter,
verify by checking if these tiles neighbor with both
non-haybale and non-perimeter tiles
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<int> x_ = {0, 0, 1, -1, 1, 1, -1, -1};
vector<int> y_ = {1, -1, 0, 0, 1, -1, 1, -1};

signed main() {
    IOS;

    int n; cin >> n;
    set<vector<int>> cows;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cows.insert({x, y});
    }

    map<vector<int>, int> visited;
    set<vector<int>> perimeter;
    map<vector<int>, int> sides;

    queue<vector<int>> q;
    q.push(*cows.begin());
    visited[*cows.begin()]++;
    while (!q.empty()) {
        auto data = q.front(); q.pop();
        int x = data[0], y = data[1];
        for (int i = 0; i < 8; i++) {
            int x1 = x + x_[i], y1 = y + y_[i];
            if (visited[{x1, y1}]) continue;
            if (cows.find({x1, y1}) != cows.end()) {
                q.push({x1, y1});
                visited[{x1, y1}]++;
            }
            else {
                perimeter.insert({x1, y1});
                if (i < 4) sides[{x1, y1}]++;
            }
        }
    }

    while (!perimeter.empty()) {
        queue<vector<int>> qp;
        qp.push(*perimeter.begin());
        visited[*perimeter.begin()]++;
        bool out = false;

        int ans = 0;
        while (!qp.empty()) {
            auto data = qp.front(); qp.pop();
            int x = data[0], y = data[1];
            for (int i = 0; i < 4; i++) {
                int x1 = x + x_[i], y1 = y + y_[i];
                if (visited[{x1, y1}]) continue;
                if (perimeter.find({x1, y1}) != perimeter.end()) {
                    qp.push({x1, y1});
                    visited[{x1, y1}]++;
                    ans += sides[{x1, y1}];
                }
                else out = true;
            }
        }

        if (out == true) {
            cout << ans << endl;
            break;
        }
    }
}