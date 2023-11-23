#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, k; cin >> r >> c >> k;
    
    vector<vector<int>> grid;
    for (int i = 0; i < r; i++) {
        vector<int> row;
        for (int j = 0; j < c; j++) {
            int k1; cin >> k1;
            row.push_back(k1);
        }
        
        grid.push_back(row);
    }
    
    int MOD = 1000000007;
    vector<vector<int>> dp(101, vector<int>(101, 0));
    dp[0][0] = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = i+1; k < r; k++) {
                for (int l = j+1; l < c; l++) {
                    if (grid[i][j] != grid[k][l]) {
                        dp[k][l] += dp[i][j];
                        dp[k][l] %= MOD;
                    }
                }
            }
        }
    }
    
    cout << dp[r-1][c-1] << endl;
}