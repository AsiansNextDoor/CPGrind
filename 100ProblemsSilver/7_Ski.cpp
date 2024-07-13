#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

vector<vector<int>> ski(100, vector<int>(100));

int ans = 0, cur = 0, r, c;
vector<int> x_ = {0, 0, 1, -1};
vector<int> y_ = {1, -1, 0, 0};
void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + x_[i];
        int ny = y + y_[i];

        if (nx >= 0 && nx < r && ny >= 0 && ny < c && ski[nx][ny] < ski[x][y]) {
            cur++;
            dfs(nx, ny);
            cur--;
        }
    }
    ans = max(cur, ans);
}

signed main() {
    IOS;

    cin >> r >> c;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ski[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) dfs(i, j);
    }

    cout << ans << endl;
}