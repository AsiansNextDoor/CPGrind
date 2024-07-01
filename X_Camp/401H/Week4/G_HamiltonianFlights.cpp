#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int n, m;
ll MOD = 1e9 + 7;
vector<vector<ll>> adj(21, vector<ll>(21, 0));
vector<vector<ll>> dp((1 << 20), vector<ll> (21, 0));


signed main() {
    IOS;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] += 1LL;
    }

    dp[1][1] = 1LL;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (!(mask & 1)) continue;
        if (((mask >> (n-1)) & 1) && mask != (1 << n) - 1) continue;
        for (int i = 0; i < n; i++) {
            if (!((mask >> i) & 1)) continue;
            int prev = mask ^ (1 << i);
            for (int j = 0; j < n; j++) {
                if (((prev >> j) & 1) && adj[j+1][i+1]) {
                    dp[mask][i+1] += dp[prev][j+1] * adj[j+1][i+1];
                    dp[mask][i+1] %= MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n] << endl;;
}