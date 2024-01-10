#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    int n, k; cin >> n >> k;
    int m; cin >> m;
    vector<vector<vector<pair<int,int>>>> grid(n+1, vector<int>(n+1, vector<int>(4)));
    vector<vector<int>> wizards(m+1, vector<int>(8));
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        string s; cin >> s;
        for (int j = 1; j <= 7; j++) {
            if (s[j-1] == 'S') wizards[i][j] = 0;
            else if (s[j-1] == 'L') wizards[i][j] = 1;
            else wizards[i][j] = 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grid[i][j][0].f = 0, grid[i][j][0].s = 0;
            grid[i][j][1].f = 0, grid[i][j][1].s = 0;
            grid[i][j][2].f = 0, grid[i][j][2].s = 0;
            grid[i][j][3].f = 0, grid[i][j][3].s = 0;
        }
    }

    int time = 1;
    int r = 1, c = 1, dir = 3; //up, down, left, right\
    int turns = 0;
    while (true) {
        if ((time %))
        if (!visited[r][c]) visited[r][c] = time;
        else {
            break;
        }
        time++;
    }
}