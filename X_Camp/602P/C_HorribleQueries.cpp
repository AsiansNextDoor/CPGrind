//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

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

    ll t; cin >> t;
    while (t--) {
        ll n, c; cin >> n >> c;
        for (ll i = 0; i < 400005; i++) {
            sum[i] = 0;
            prop[i] = 0;
        }
        for (ll i = 0; i < c; i++) {
            ll type; cin >> type;
            if (type) {
                ll p, q; cin >> p >> q;
                cout << (query(1, 1, n, p, q))[0] << endl;
            }
            else {
                ll p, q, v; cin >> p >> q >> v;
                range(1, 1, n, p, q, v);
            }
        }
    }
}