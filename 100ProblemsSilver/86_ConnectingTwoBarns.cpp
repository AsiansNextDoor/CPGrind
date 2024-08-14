#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

vector<ll> p(1e6);
vector<ll> s(1e6);

void make_set(ll v) {
    p[v] = v;
    s[v] = 1;
}

ll find_set(ll v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (s[a] < s[b])
            swap(a, b);
        p[b] = a;
        s[a] += s[b];
    }
}

vector<ll> u_ = {1, -1};

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;

        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < m ; i++) {
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (ll i = 1; i <= n; i++) make_set(i);

        queue<ll> bfs;
        vector<ll> vdsu(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            if (vdsu[i]) continue;
            bfs.push(i);
            vdsu[i]++;
            while (!bfs.empty()) {
                ll u = bfs.front(); bfs.pop();
                union_sets(i, u);
                for (ll v: adj[u]) {
                    if (vdsu[v]) continue;
                    bfs.push(v);
                    vdsu[v]++;
                }
            }
        }
        for (ll i = 1; i <= n; i++) find_set(i);

        vector<ll> visited(n + 1, 0);

        queue<ll> bfs1;

        bfs.push(1);
        visited[1]++;

        vector<ll> dist(n + 1, n);
        while (!bfs.empty()) {
            ll u = bfs.front(); bfs.pop();
            
            bfs1.push(u);
            dist[p[u]] = 0;
            for (ll v: adj[u]) {
                if (visited[v]) continue;
                bfs.push(v);
                visited[v]++;
            }
        }


        while (!bfs1.empty()) {
            ll u = bfs1.front(); bfs1.pop();
            
            for (ll i = 0; i <= 1; i++) {
                ll u1 = u + u_[i];
                if (u1 <= 0 || u1 > n || visited[u1]) continue;
                bfs1.push(u1);
                visited[u1]++;
                dist[p[u1]] = min(dist[p[u]] + 1, dist[p[u1]]);
            }
        }

        vector<ll> visitedn(n + 1, 0);

        bfs.push(n);
        visitedn[n]++;

        vector<ll> distn(n + 1, n);
        while (!bfs.empty()) {
            ll u = bfs.front(); bfs.pop();
            
            bfs1.push(u);
            distn[p[u]] = 0;
            for (ll v: adj[u]) {
                if (visitedn[v]) continue;
                bfs.push(v);
                visitedn[v]++;
            }
        }

        while (!bfs1.empty()) {
            ll u = bfs1.front(); bfs1.pop();
            
            for (ll i = 0; i <= 1; i++) {
                ll u1 = u + u_[i];
                if (u1 <= 0 || u1 > n || visitedn[u1]) continue;
                bfs1.push(u1);
                visitedn[u1]++;
                distn[p[u1]] = min(distn[p[u]] + 1, distn[p[u1]]);
            }
        }
        

        ll ans = 1e17;
        for (ll i = 1; i <= n; i++) ans = min(dist[p[i]] * dist[p[i]] + distn[p[i]] * distn[p[i]], ans);

        cout << ans << endl;
    }
}