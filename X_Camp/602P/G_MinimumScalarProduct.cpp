//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD;

signed main() {
    IOS;

    ll t; cin >> t;
    for (ll test = 1; test <= t; test++) {
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ans += a[i] * b[i];
        }

        cout << "Case #" << test << ": " << ans << endl;
    }
}