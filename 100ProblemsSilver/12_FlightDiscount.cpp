#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll n, m;
ll INF = 1e15;
void dijkstra (ll r, vector<vector<vector<ll>>> adj, vector<ll> & d) {
    d[r] = 0;

    set<vector<ll>> s; // cost, node;
    s.insert({0, r});
    while (!s.empty()) {
        auto data = *s.begin(); s.erase(s.begin());
        ll u = data[1];

        for (auto vdata: adj[u]) {
            ll v = vdata[0], c = vdata[1];
            if (d[u] + c < d[v]) {
                s.erase({d[v], v});
                d[v] = d[u] + c;
                s.insert({d[v], v});
            }
        }
    }
}

signed main() {
    IOS;

    cin >> n >> m;

    // dijkstra on both sides
    vector<vector<vector<ll>>> adj1(n+1), adj2(n+1); // node, cost

    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }

    vector<ll> d1(n+1, INF), d2(n+1, INF);
    dijkstra(1, adj1, d1);
    dijkstra(n, adj2, d2);

    ll ans = INF;
    for (ll a = 0; a < n; a++) {
        for (auto data: adj1[a]) {
            ll b = data[0];
            ll c = data[1];
            ans = min(d1[a] + c / 2 + d2[b], ans);
        }
    }

    cout << ans << endl;
}