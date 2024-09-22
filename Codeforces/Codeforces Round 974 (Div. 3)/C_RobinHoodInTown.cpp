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
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];

        if (n <= 2) {
            cout << -1 << endl;
            continue;
        }

        sort(a.begin(), a.end());

        ll w = a[n / 2] * 2 * n;
        for (ll i = 0; i < n; i++) w -= a[i];

        cout << max(w + 1, 0LL) << endl;
    }
}