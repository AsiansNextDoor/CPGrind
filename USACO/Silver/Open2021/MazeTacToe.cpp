//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

int n;
map<int, vector<char>> pos;
int maze[25][25];
map<vector<vector<char>>, int> visited[25][25];

vector<int> mx_ = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> my_ = {-1, -1, -1, 0, 0, 1, 1, 1};
bool check(vector<vector<char>> s1) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s1[i][j] == 'M') {
                for (int m = 0; m < 8; m++) {
                    int x = i, y = j;
                    bool found = true;
                    for (int k = 0; k < 2; k++) {
                        x += mx_[m], y += my_[m];
                        if (x < 0 || x >= 3 || y < 0 || y >= 3) found = false;
                        else if (s1[x][y] != 'O') found = false;
                    }
                    if (found) return true;
                }
            }
        }
    }
    return false;
}

set<vector<vector<char>>> ans;
vector<int> x_ = {0, 0, 1, -1};
vector<int> y_ = {1, -1, 0, 0};
void dfs(int x, int y, vector<vector<char>> s1) {
    if (check(s1)) {
        ans.insert(s1);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int x1 = x + x_[i];
        int y1 = y + y_[i];

        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) continue;
        if (maze[x1][y1] == -1) continue;
        else if (maze[x1][y1] == 0) {
            if (!visited[x1][y1][s1]) {
                visited[x1][y1][s1]++;
                dfs(x1, y1, s1);
            }
        }
        else {
            auto data = pos[maze[x1][y1]];
            char c = data[0];
            int n1 = data[1] - '1', n2 = data[2] - '1';

            auto s2 = s1;
            if (!s2[n1][n2]) s2[n1][n2] = c;
            if (!visited[x1][y1][s2]) {
                visited[x1][y1][s2]++;
                dfs(x1, y1, s2);
            }
        }
    }
}

signed main() {
    IOS;

    cin >> n;
    int id = 1, sx, sy;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            char c = s[j * 3];
            if (c == '#') maze[i][j] = -1;
            else if (c == 'B') sx = i, sy = j;
            else if (c != '.') {
                char n1 = s[j * 3 + 1];
                char n2 = s[j * 3 + 2];
                pos[id] = {c, n1, n2};
                maze[i][j] = id;
                id++;
            }
        }
    }

    visited[sx][sy][vector<vector<char>>(3, vector<char>(3))]++;
    dfs(sx, sy, vector<vector<char>>(3, vector<char>(3)));

    cout << ans.size() << endl;
}