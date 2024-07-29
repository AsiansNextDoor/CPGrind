#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x+1, 1e6+1);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c: coins) {
            if (c > i || dp[i-c] == 1e6+1) continue;
            dp[i] = min(dp[i-c] + 1, dp[i]);
        }
    }

    if (dp[x] == 1e6+1) dp[x] = -1;
    cout << dp[x] << endl;
}