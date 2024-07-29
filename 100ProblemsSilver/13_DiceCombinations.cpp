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

    ll n; cin >> n;
    vector<ll> dp(1e6+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    for (ll i = 7; i <= n; i++) {
        dp[i] = dp[i-6] + dp[i-5] + dp[i-4] + dp[i-3] + dp[i-2] + dp[i-1];
        dp[i] %= MOD;
    }

    cout << dp[n] << endl;
}