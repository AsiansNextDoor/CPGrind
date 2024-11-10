//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD;

ll n, ans = 0, minmoo;
vector<ll> moo;
vector<ll> adj;
vector<ll> visited;

ll dfscycle(ll u) {
    if (visited[u] == 2) {
        return ans -= minmoo;
    }
    visited[u] = 2;
    minmoo = min(moo[u], minmoo);
    dfscycle(adj[u]);

    return 0;
}

ll dfs(ll u) {
    if (visited[u] == 1) return dfscycle(u);

    else if (visited[u] == 2) return 0;
    visited[u] = 1;
    ans += moo[u];
    dfs(adj[u]);
    visited[u] = 2;

    return 0;
}

signed main() {
    IOS;

    ll n; cin >> n;
    moo.resize(n);
    adj.resize(n);
    visited.resize(n);

    for (ll i = 0; i < n; i++) {
        ll ai, vi; cin >> ai >> vi;
        moo[i] = vi;
        adj[i] = ai - 1;
    }

    for (ll i = 0; i < n; i++) {
        minmoo = 1e9;
        dfs(i);
    }

    cout << ans << endl;
}