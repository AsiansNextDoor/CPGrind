#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <array>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        vector<vector<int>> visited(n, vector<int>(m, 2));

        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == 'D') grid[i][j] = 1;
                else if (s[j] == 'L') grid[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n-1) visited[i][j]--;
                if (j == m-1) visited[i][j]--;
            }
        }

        
    }
}