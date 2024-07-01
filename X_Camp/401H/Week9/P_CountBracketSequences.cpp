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

    string s; cin >> s;
    ll n = s.length();

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0)); //dp[index][number of left parenthesis]
    dp[0][0] = 1;

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (s[i] != ')') {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
            if (s[i] != '(' && j > 0) {
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= MOD;
            }
        }
    }

    cout << dp[n][0] << endl;
}