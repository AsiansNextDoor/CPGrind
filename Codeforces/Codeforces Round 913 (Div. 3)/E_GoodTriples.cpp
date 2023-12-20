#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        
        ll ans = 1;
        ll length = to_string(n).length();
        for (ll i = 0; i < length; i++) {
            ll mult = 0;
            ll d = n % 10;
            n /= 10;
            for (ll j = 0; j <= d; j++) {
                for (ll k = 0; k <= d; k++) {
                    if (j + k <= d) {
                        mult++;
                    }
                }
            }
            
            ans *= mult;
        }
        
        cout << ans << endl;
    }
}