#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second


ll MOD = 1e9 + 7;


vector<bool> visited;
vector<vector<ll>> dp;
vector<ll> colors;
vector<vector<ll>> adj;


void dfs(ll p, ll u) {
    for (int v: adj[u]) {
        if (v != p) dfs(u, v);
    }
    for (ll c = 1; c <= 3; c++) {
        ll paint = 1;
        if (colors[u] != 0 && colors[u] != c) {
            dp[u][c] = 0;
            continue;
        }
        for (ll v: adj[u]) {
            if (v == p) continue;
            ll change = 0;
            for (ll c2 = 1; c2 <= 3; c2++) {
                if (c == c2) continue;
                change += dp[v][c2];
                change %= MOD;
            }
            paint *= change;
            paint %= MOD;
        }
        if (adj[u].size() == 1 && adj[u][0] == p) paint = 1;
        dp[u][c] = paint;
        //cout << u << " " << c << " " << paint << endl;
    }
}


signed main() {
    IOS;

    freopen("barnpainting.in", "r", stdin); 
    freopen("barnpainting.out", "w", stdout);

    ll n, k; cin >> n >> k;
    visited.resize(n+1, false);
    dp.resize(n+1, vector<ll>(4, 0));
    colors.resize(n+1, 0);
    adj.resize(n+1);


    for (ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 0; i < k; i++) {
        ll b; cin >> b >> colors[b];
    }
    dfs(0, 1);
    ll ans = dp[1][1] + dp[1][2] + dp[1][3];
    ans %= MOD;
    cout << ans << endl;
}

