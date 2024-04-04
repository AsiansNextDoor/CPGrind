#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll n; cin >> n;
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        ll l; cin >> l;
        s.insert(l);
    }

    n = s.size();
    vector<ll> c;
    for (ll i: s) c.push_back(i);

    if (n <= 3) { // all L's less than or equal to a fourth of the smallest month are valid
        ll num = c[0]/4;
        cout << num * (num + 1) / 2 << endl;
    }
    else {
        set<ll> factors;
        for (ll i = 0; i < 3; i++) {
            for (ll j = i+1; j < 4; j++) {
                ll num = abs(c[i] - c[j]);
                for (ll f1 = 1; f1*f1 <= num; f1++) {
                    if (num % f1 == 0) {
                        factors.insert(f1);
                        factors.insert(num/f1);
                    }
                }
            }
        }

        ll ans = 0;
        for (ll i: factors) {
            if (i > c[0]/4) break;
            bool valid = true;
            set<ll> vals;
            for (ll j: c) {
                vals.insert(j % i);
            }

            if (vals.size() <= 3) ans += i;
        }

        cout << ans << endl;
    }
}