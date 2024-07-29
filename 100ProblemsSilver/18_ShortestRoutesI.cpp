#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll INF = 1e15;

signed main() {
    IOS;

    ll n, m; cin >> n >> m;

    vector<vector<vector<ll>>> adj(n+1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> d(n+1, INF);
    d[1] = 0;

    set<vector<ll>> s;
    s.insert({0, 1});
    while (!s.empty()) {
        auto data = *s.begin(); s.erase(s.begin());
        ll u = data[1];

        for (auto data2: adj[u]) {
            ll v = data2[0];
            ll c = data2[1];
            if (d[u] + c < d[v]) {
                s.erase({d[v], v});
                d[v] = d[u] + c;
                s.insert({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}