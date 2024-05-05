#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll n, k; 
vector<vector<ll>> dp_down(50001, vector<ll>(501, 0));
vector<vector<ll>> dp_up(50001, vector<ll>(501, 0));
vector<vector<ll>> adj(50001);

void dfs1(ll u, ll p) {
    for (ll v: adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        for (ll i = 1; i <= k; i++) dp_down[u][i] += dp_down[v][i-1];
    }
}

void dfs2(ll u, ll p) {
    for (ll i = 1; i <= k; i++) {
        if (u == 1) break;
        dp_up[u][i] = dp_up[p][i-1] + dp_down[p][i-1];

        if (i == 1) {
            dp_up[u][i]--;
        }
        else {
            dp_up[u][i] -= dp_down[u][i-2];
        }
    }
    for (ll v: adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
}

signed main() {
    IOS;
    cin >> n >> k;

    for (ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        dp_down[i][0]++;
        dp_up[i][0]++;
    }   
    dfs1(1, 0);
    dfs2(1, 0);

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += dp_down[i][k] + dp_up[i][k];
    }

    cout << ans / 2 << endl;
}