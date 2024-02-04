#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

const ll maxn = 1e5+3;

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<vector<ll>> tree(n+1);
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<ll> shake(m);
        for (ll i = 0; i < m; i++) cin >> shake[i];

        ll leaves = 0;
        vector<ll> dist(maxn, 0);
        queue<vector<ll>> bfs;
        bfs.push({1, 0, 0});
        while (!bfs.empty()) {
            auto data = bfs.front(); bfs.pop();
            ll node = data[0], parent = data[1], d = data[2];

            bool leaf = true;
            for (ll i : tree[node]) {
                if (i != parent) {
                    bfs.push({i, node, d+1});
                    leaf = false;
                }
            }

            if (leaf) {
                leaves++;
                dist[d]++;
            }
        }

        for (ll i = 1; i < maxn; i++) {
            dist[i] += dist[i-1];
        }

        vector<ll> dp(maxn, 0);

        for (ll i = 1; i < maxn; i++) {
            dp[i] = dp[i-1] + dist[i];
        }
        ll ans = 0;

        ll prev = 1;
        for (ll i = 0; i < m; i++) {
            //cout << "i: " << i << endl;
            ll time = shake[i] - prev;
            prev = shake[i]+1;

            if (time >= maxn) ans += dp[maxn-1] + (time - (maxn-1)) * leaves;
            else ans += dp[time];
        }

        cout << ans << endl;
    }
}