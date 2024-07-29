#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll MOD = 1e9 + 7;

signed main() {
    IOS;

    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];

    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= x; i++) {
        for (ll c: coins) {
            if (c > i) continue;
            dp[i] += dp[i-c];
        }
        dp[i] %= MOD;
    }
    cout << dp[x] << endl;
}