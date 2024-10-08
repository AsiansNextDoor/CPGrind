//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD = 1e9 + 7;

ll sum[400005];
ll prop[400005];

vector<ll> query(ll p, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return {0, 0};
    if (ql <= l && r <= qr) 
        return {sum[p] + prop[p] * (r - l + 1), (r - l + 1)};

    ll m = (l + r) / 2;
    auto q1 = query(2 * p, l, m, ql, qr);
    auto q2 = query(2 * p + 1, m + 1, r, ql, qr);
    return {q1[0] + q2[0] + (q1[1] + q2[1]) * prop[p], q1[1] + q2[1]};
}

void update(ll p, ll l, ll r, ll idx, ll val) {
    if (l == r) {
        sum[p] += val;
        return;
    }

    ll m = (l + r) / 2;
    if (idx <= m) update(2 * p, l, m, idx, val);
    else update(2 * p + 1, m + 1, r, idx, val);
    sum[p] = (sum[2 * p] + sum[2 * p + 1]);
}

ll range(ll p, ll l, ll r, ll ql, ll qr, ll val) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) {
        prop[p] += val;
        return val * (r - l + 1);
    }
    
    ll m = (l + r) / 2;
    ll r1 = range(2 * p, l, m, ql, qr, val);
    ll r2 = range(2 * p + 1, m + 1, r, ql, qr, val);
    sum[p] += r1 + r2;
    return r1 + r2;
}

signed main() {
    IOS;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<ll> pows(1e6 + 1);
    ll p = 31;
    ll ppow = 1;
    for (int i = 0; i <= 1e6; i++) {
        pows[i] = ppow;
        ppow = (ppow * p) % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        vector<int> pa(n, a[0]);
        for (int i = 1; i < n; i++) {
            pa[i] = ((pows[i] * a[i]) + a[i - 1]) % MOD;
        }

        map<int, int> ra;
        for (int i = 0; i < n; i++) ra[a[i]] = i;

        ordered_set ord;
        map<int, set<int>> occ;
        for (int i = 0; i < m; i++) {
            ord.insert(b[i]);
            occ[b[i]].insert(i);
        }
        for (int i = 0; i < m; i++) occ[b[i]].insert(i);

        while (q--) {
            int s, t; cin >> s >> t;
        } 

    }
}