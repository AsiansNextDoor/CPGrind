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
        ll n, k; cin >> n >> k;
        vector<pair<ll,ll>> xa(n);
        for (ll i = 0; i < n; i++) {
            int a; cin >> a;
            xa[i].s = a;
        }
        for (ll i = 0; i < n; i++) {
            int x; cin >> x;
            xa[i].f = abs(x);
        }

        sort(xa.begin(), xa.end());

        ll sum = 0;
        bool alive = true;
        for (int i = 0; i < n; i++) {
            sum += xa[i].s;
            if (sum > xa[i].f * k) {
                alive = false;
                break;
            }
        }

        if (!alive) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}