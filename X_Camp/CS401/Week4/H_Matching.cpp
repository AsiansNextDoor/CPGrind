#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define f first
#define s second

ll n;
ll MOD = 1e9 + 7;
vector<vector<ll>> adj(21, vector<ll>(21, 0));
vector<ll> dp((1 << 21));


signed main() {
    IOS;

    cin >> n;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    dp[0] = 1;
    for (ll mask = 0; mask < (1LL << n) - 1; mask++) {
        for (ll i = 0; i < n; i++) {
            ll next = (1LL << i);
            if (next & mask) {
                continue;
            }

            ll cnt = 0;
            for (ll j = 0; j < n; j++) {
                if ((mask >> j) & 1) {
                    cnt++;
                }
            }
            if (adj[cnt][i]) {
                dp[mask ^ next] += dp[mask];
                dp[mask ^ next] %= MOD;
            }
        }
    }

    cout << dp[(1LL << n) - 1];
}