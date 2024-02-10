#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n, m, d, k; cin >> n >> m >> d >> k;
    vector<vector<int>> farm(n, vector<int>(m, 0));
    vector<vector<int>> psum(n+1, vector<int>(m+1, 0));

    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] == 'M') {
                farm[i][j] = 1;
            }
            else if (row[j] == 'S') {
                //cout << i << " " << j << endl;
                int x1 = max(i-d, 0);
                int y1 = max(j-d, 0);
                int x2 = min(i+d, n-1);
                int y2 = min(j+d, m-1);
                psum[x1][y1] += 1;
                psum[x2+1][y1] -= 1;
                psum[x1][y2+1] -= 1;
                psum[x2+1][y2+1] += 1;
            }
        }
    }
    //for (int i = 0; i <= n; i++){
        //for (int j = 0; j <= m; j++) {
            //cout << psum[i][j] << " ";
        //}
        //cout << endl;
    //}
    
    for (int i = 1; i <= n; i++) psum[i][0] += psum[i-1][0];
    for (int i = 1; i <= m; i++) psum[0][i] += psum[0][i-1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (farm[i][j] == 1 && psum[i][j] >= k) ans++;
        }
    }

    cout << ans << endl;
}