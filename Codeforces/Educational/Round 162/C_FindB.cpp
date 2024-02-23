#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        vector<ll> c(n+1);
        vector<ll> p(n+1, 0);
        vector<ll> p1(n+1, 0);
        for (ll i = 1; i <= n; i++) cin >> c[i];
        for (ll i = 1; i <= n; i++) {
            p[i] += p[i-1];
            p1[i] += p1[i-1];
            if (c[i] == 1) p1[i]++;
            else p[i] += c[i] - 1;
        }

        //for (ll i = 1; i <= n; i++) cout << p[i] << " ";
        //cout << endl;
        //for (ll i = 1; i <= n; i++) cout << p1[i] << " ";
        //cout << endl;

        while (q--) {
            ll l, r; cin >> l >> r;
            ll v1 = p[r] - p[l-1];
            ll v2 = p1[r] - p1[l-1];

            if (r-l == 0 || v1 < v2) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}