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

    ll n; cin >> n;
    
    vector<ll> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (ll i = 4; i <= n; i++) dp[i] += dp[i-3] + dp[i-2] + dp[i-1];

    cout << dp[n] % MOD << endl;
}