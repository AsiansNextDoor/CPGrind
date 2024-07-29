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

    ll n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for (ll i = 1; i <= n; i++) dist[i][i] = 0;
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
            }
        }
    }

    while (q--) {
        ll a, b; cin >> a >> b;
        if (dist[a][b] == INF) dist[a][b] = -1;
        cout << dist[a][b] << endl;
    }
}