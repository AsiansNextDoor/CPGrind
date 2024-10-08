//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll tot[3000005];

// node index, [l, r] for node range, [ql, qr] for query range
ll query(ll p, ll l, ll r, ll ql, ll qr) {
    // no overlap between query and node range
    if (ql > r || qr < l) return 0;
    // node range completely covered by query
    if (ql <= l && r <= qr) return tot[p];
    // keep descending down
    // 2 * p and 2 * p + 1 are left and right child
    ll m = (l + r) / 2;
    return (query(2 * p, l, m, ql, qr) + query(2 * p + 1, m + 1, r, ql, qr));
}

// node index, [l, r] for node range, set element at idx to val
void update(ll p, ll l, ll r, ll idx, ll val) {
    if (l == r) { // leaf node
        tot[p] += val;
        return;
    }

    // descend down correct branch that the leaf is under
    ll m = (l + r) / 2;
    if (idx <= m) update(2 * p, l, m, idx, val);
    else update(2 * p + 1, m + 1, r, idx, val);
    tot[p] = (tot[2 * p] + tot[2 * p + 1]); // recalculate value
}

signed main() {
    IOS;

    ll n, m; cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;
        update(1, 1, n, i, a);
    }

    while (m--) {
        ll q, x, y; cin >> q >> x >> y;
        x++;
        if (q) cout << query(1, 1, n, x, y) << endl;
        else update(1, 1, n, x, y);
    }
}