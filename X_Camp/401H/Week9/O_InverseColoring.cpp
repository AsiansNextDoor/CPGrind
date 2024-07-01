#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll MOD = 998244353;

signed main() {
    IOS;

    ll n, k; cin >> n >> k;

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0)); // index, max length of rectangle
    dp[0][0] = 1;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= n; j++) {
            for (ll len = 1; len <= n - i; len++) {
                dp[i+len][max(j, len)] += dp[i][j];
                dp[i+len][max(j, len)] %= MOD;
            }
        }
    }

    ll ans = 0;
    for (ll x = 1; x < min(n+1, k); x++) {
        for (ll y = 1; y <= min(n, (k/x)); y++) {
            if (x * y >= k) break;
            ans += dp[n][x] * dp[n][y];
            ans %= MOD;
        }
    }

    cout << (2 * ans) % MOD << endl;
}