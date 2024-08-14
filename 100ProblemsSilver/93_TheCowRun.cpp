#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

signed main() {
    IOS;

    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);

    ll n; cin >> n;
    vector<ll> cows(n);
    for (ll i = 0; i < n; i++) cin >> cows[i];

    sort(cows.begin(), cows.end());

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 1e15)));

    ll r = upper_bound(cows.begin(), cows.end(), 0) - cows.begin();
    if (r != 0) {
        dp[r - 1][r - 1][0] = (-cows[r - 1]) * n;
        dp[r - 1][r - 1][1] = (-cows[r - 1]) * n;
    }
    if (r != n) {
        dp[r][r][0] = cows[r] * n;
        dp[r][r][1] = cows[r] * n;
    }

    for (ll len = 0; len < n - 1; len++) {
        for (ll i = 0; i < n - len; i++) {
            ll j = i + len;
            ll cow = n - (j - i) - 1;
            if (dp[i][j][0] == 1e7 && dp[i][j][1] == 1e7) continue;
            if (i > 0) {
                ll lcost = (cows[i] - cows[i - 1]) * cow;
                ll rcost = (cows[j] - cows[i - 1]) * cow;
                ll mcost = min(lcost + dp[i][j][0], rcost + dp[i][j][1]);
                dp[i - 1][j][0] = min(mcost, dp[i - 1][j][0]);
            }
            if (j < n - 1) {
                ll lcost = (cows[j + 1] - cows[i]) * cow;
                ll rcost = (cows[j + 1] - cows[j]) * cow;
                ll mcost = min(lcost + dp[i][j][0], rcost + dp[i][j][1]);
                dp[i][j + 1][1] = min(mcost, dp[i][j + 1][1]);
            }
        }
    }

    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
}