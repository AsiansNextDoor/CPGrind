#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n, k; cin >> n >> k;

    vector<vector<int>> barn(2e3, vector<int>(2e3, 0));

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        barn[x1 + 1][y1 + 1]++;
        barn[x1 + 1][y2 + 1]--;
        barn[x2 + 1][y1 + 1]--;
        barn[x2 + 1][y2 + 1]++;
    }

    int ans = 0;
    vector<vector<int>> psum(2e3, vector<int>(2e3, 0));
    for (int i = 1; i <= 1e3 + 5; i++) {
        for (int j = 1; j <= 1e3 + 5; j++) {
            psum[i][j] = barn[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
            if (psum[i][j] == k) ans++;
        }
    }

    cout << ans << endl;
}