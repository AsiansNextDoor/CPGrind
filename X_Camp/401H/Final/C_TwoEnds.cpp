#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n; cin >> n;
    int game = 1;
    while (n != 0) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        for (int i = 0; i < n; i++) dp[i][i] = -a[i];

        for (int len = 1; len < n; len++) {
            for (int i = 0; i < n - len; i++) {
                int j = i + len;
                if (len % 2 == 0) {
                    if (a[i] < a[j]) dp[i][j] = dp[i][j-1] - a[j];
                    else dp[i][j] = dp[i+1][j] - a[i];
                }
                else {
                    dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
                }
            }
        }

        cout << "In game " << game << ", the greedy strategy might lose by as many as " << dp[0][n-1] << " points." << endl;

        cin >> n;
        game++;
    }
}