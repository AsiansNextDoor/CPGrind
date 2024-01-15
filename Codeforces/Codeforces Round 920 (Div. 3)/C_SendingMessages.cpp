#include <bits/stdc++.h>
using namespace std;

/*
Debug checklist
- Check bounds
- Long long
- Sample case
- Edge cases
*/

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        ll n, f, a, b; cin >> n >> f >> a >> b;
        vector<ll> m(n);
        for (ll i = 0; i < n; i++) {
            cin >> m[i];
        }
        ll time = 0;
        bool valid = true;
        for (ll i = 0; i < n; i++) {
            f -= min((m[i]-time)*a, b);
            time = m[i];

            if (f <= 0) {
                valid = false;
                break;
            }
        }

        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}