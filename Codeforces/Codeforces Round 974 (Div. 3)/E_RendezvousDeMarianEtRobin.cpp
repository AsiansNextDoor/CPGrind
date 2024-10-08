//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const ll INF = 1000000000000;

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        ll n, m, h; cin >> n >> m >> h;
        vector<ll> hnodes(n + 1, 0);
        for (ll i = 0; i < h; i++) {
            ll c; cin >> c;
            hnodes[c]++;
        }
        vector<vector<vector<ll>>> adj(n+1); // foot, horse
        for (ll i = 0; i < m; i++) {
            ll u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<ll>> d(2, vector<ll>(n + 1, INF));

        d[0][1] = 0;
        set<array<ll, 3>> q;
        q.insert({0, 1, 0});
        while (!q.empty()) {
            ll u = (*q.begin())[1], prevh = (*q.begin())[2];
            q.erase(q.begin());

            ll curh = hnodes[u] || prevh;


            for (auto edge: adj[u]) {
                ll to = edge[0];
                ll len = (curh) ? edge[1] / 2 : edge[1];

                if (d[prevh][u] + len < d[curh][to]) {
                    q.erase({d[prevh][to], to, prevh});
                    q.erase({d[curh][to], to, curh});
                    d[curh][to] = d[prevh][u] + len;
                    q.insert({d[curh][u], to, curh});
                }
            }
        }
        vector<vector<ll>> nd(2, vector<ll>(n + 1, INF));

        nd[0][n] = 0;
        set<array<ll, 3>> nq; // cost, node, horse
        nq.insert({0, n, 0});
        while (!nq.empty()) {
            ll u = (*nq.begin())[1], prevh = (*nq.begin())[2];
            nq.erase(nq.begin());

            ll curh = hnodes[u] || prevh;


            for (auto edge: adj[u]) {
                ll to = edge[0];
                ll len = (curh) ? edge[1] / 2 : edge[1];

                if (nd[prevh][u] + len < nd[curh][to]) {
                    nq.erase({nd[prevh][to], to, prevh});
                    nq.erase({nd[curh][to], to, curh});
                    nd[curh][to] = nd[prevh][u] + len;
                    nq.insert({nd[curh][u], to, curh});
                }
            }
        }

        ll ans = INF;
        for (ll i = 1; i <= n; i++) {
            ll tot = max(min(d[0][i], d[1][i]), min(nd[0][i], nd[1][i]));
            ans = min(tot, ans);
        }

        if (ans >= INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}