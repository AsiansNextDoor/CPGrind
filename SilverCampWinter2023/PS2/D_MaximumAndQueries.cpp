#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    ll n, q; cin >> n >> q;
    vector<ll> in(n), a;
    for (ll i = 0; i < n; i++) cin >> in[i];

    while (q--) {
        ll k; cin >> k;
        a = in;
        ll ans = 0;
        for (ll i = 60; i >= 0; i--) {
            ll cur = (1ll << i);
            ll cnt = 0;
            for (ll j = 0; j < n; j++) {
                if (a[j] & cur) continue; // if bit is turned on
                else {
                    cnt += (cur - (a[j] & (cur - 1LL))); // amount needed to turn on
                }
                if (cnt > k) break;
            }

            if (cnt <= k) {
                for (ll j = 0; j < n; j++) {
                    if (a[j] & cur) continue;
                    else {
                        a[j] -= (a[j] & ((1ll << i+1) - 1));
                        a[j] += cur;
                    }
                }
                k -= cnt;
                ans += cur;
            }
        }
        cout << ans << endl;
    }
}