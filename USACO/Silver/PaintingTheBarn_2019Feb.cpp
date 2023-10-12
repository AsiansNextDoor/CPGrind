#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k; cin >> n >> k;
    
    vector<vector<int>> barn(1002, vector<int>(1002, 0));
    vector<vector<int>> psums(1002, vector<int>(1002, 0));
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++;
        y1++;
        x2++;
        y2++;
        barn[x1][y1] += 1;
        barn[x1][y2] -= 1;
        barn[x2][y1] -= 1;
        barn[x2][y2] += 1;
    }
    
    
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            psums[i][j] = barn[i][j] + psums[i-1][j] + psums[i][j-1] - psums[i-1][j-1];
        }
    }
    
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (psums[i][j] == k) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
}