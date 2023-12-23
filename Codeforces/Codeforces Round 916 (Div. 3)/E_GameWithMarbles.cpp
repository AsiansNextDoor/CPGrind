#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
signed main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n), b(n);
 
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];
 
        multiset<vector<ll>> ms;
 
        for (ll i = 0; i < n; i++) ms.insert({a[i]+b[i], a[i], b[i]});
 
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            auto it = ms.end(); it--;
            auto data = *it;
            ms.erase(it);
            if (i % 2 == 0) {
                ans += data[1]-1;
            }
            else {
                ans -= data[2]-1;
            }
        }
 
        cout << ans << endl;
    }
}