#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n+1, vector<int>(m+1, 1e6)); //1 indexed


    for (int i = 1; i <= n; i++) {
        string row; cin >> row;
        for (int j = 1; j <= m; j++) {
            if (row[j-1] != 'x') continue;
            for (int col = 1; col <= m; col++) {
                int dist = abs(col - j);
                grid[i][col] = min(dist * dist , grid[i][col]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
 
    //cout << "q" << endl;
    int q; cin >> q; //cout << q << endl;
    while (q--) {
        //cout << "check1" << endl;
        int r, c; cin >> r >> c;

        int ans = 1e6;
        for (int i = 1; i <= n; i++) {
            int dist = abs(i - r);
            ans = min(grid[i][c] + (dist * dist), ans);
        }

        cout << ans << endl;

        for (int i = 1; i <= m; i++) {
            int dist = abs(c - i);
            grid[r][i] = min(dist * dist , grid[r][i]);
        }
    }
} `