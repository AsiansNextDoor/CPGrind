//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF = -1000000000;
ll tot[400005][4] = {INF}; // max subarray, max left prefix, max right prefix, all

// node index, [l, r] for node range, [ql, qr] for query range
vector<ll> query(ll p, ll l, ll r, ll ql, ll qr) {
    // no overlap between query and node range
    if (ql > r || qr < l) return {INF, INF, INF, INF};
    // node range completely covered by query
    if (ql <= l && r <= qr) {
        return {tot[p][0], tot[p][1], tot[p][2], tot[p][3]};
    }
    // keep descending down
    // 2 * p and 2 * p + 1 are left and right child
    ll m = (l + r) / 2;
    auto q1 = query(2 * p, l, m, ql, qr);
    auto q2 = query(2 * p + 1, m + 1, r, ql, qr);
    ll all = q1[3] + q2[3];
    ll left = max(max(q1[1], q1[3] + q2[1]), max(q1[3], all));
    ll right = max(max(q2[2], q2[3] + q1[2]), max(q2[3], all));
    ll cen = max(max(max(max(left, right), all), q1[2] + q2[1]), max(q1[0], q2[0]));
    return {cen, left, right, all};
}

// node index, [l, r] for node range, set element at idx to val
void update(ll p, ll l, ll r, ll idx, ll val) {
    if (l == r) { // leaf node
        tot[p][0] = val;
        tot[p][1] = val;
        tot[p][2] = val;
        tot[p][3] = val;
        return;
    }

    ll m = (l + r) / 2;
    if (idx <= m) update(2 * p, l, m, idx, val);
    else update(2 * p + 1, m + 1, r, idx, val);
    
    tot[p][3] = tot[2 * p][3] + tot[2 * p + 1][3];
    tot[p][1] = max(max(tot[2 * p][1], tot[2 * p][3] + tot[2 * p + 1][1]), max(tot[2 * p][3], tot[p][3]));
    tot[p][2] = max(max(tot[2 * p + 1][2], tot[2 * p + 1][3] + tot[2 * p][2]), max(tot[2 * p + 1][3], tot[p][3]));
    tot[p][0] = max(max(max(max(tot[p][1], tot[p][2]), tot[p][3]), tot[2 * p][2] + tot[2 * p + 1][1]), max(tot[2 * p][0], tot[2 * p + 1][0]));
}

signed main() {
    IOS;


    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll a; cin >> a;
        update(1, 1, n, i, a);
    }

    ll m; cin >> m;
    while (m--) {
        ll q, x, y; cin >> q >> x >> y;
        if (q) cout << (query(1, 1, n, x, y))[0] << endl;
        else update(1, 1, n, x, y);
    }
}