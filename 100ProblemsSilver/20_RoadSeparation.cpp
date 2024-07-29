#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll n, m;
ll ans, cnt;
vector<ll> p(1e5+1), r(1e5+1); //parent, rank

void make_set(ll u) {
    p[u] = u;
    r[u] = 0;
}

ll find_set(ll u) {
    if (p[u] == u) return u;
    return p[u] = find_set(p[u]);
}

void merge_set(ll u, ll v, ll c) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    if (r[u] < r[v]) swap(u, v);
    if (r[u] == r[v]) r[u]++;
    p[v] = u;

    ans += c;
    cnt++;
}

vector<vector<ll>> roads;

signed main() {
    IOS;

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }

    sort(roads.begin(), roads.end());

    for (ll i = 1; i <= n; i++) make_set(i);
    for (auto data: roads) merge_set(data[1], data[2], data[0]);
    if (cnt != n-1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}