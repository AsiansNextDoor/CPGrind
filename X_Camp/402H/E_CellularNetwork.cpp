#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

ll n;
vector<ll> cities;
vector<ll> towers;

bool check(ll r) {
    for (ll c: cities) {
        ll diff = upper_bound(towers.begin(), towers.end(), c + r) - 
        lower_bound(towers.begin(), towers.end(), c - r);
        if (!diff) return false;
    }
    return true;
}

signed main() {
    IOS;

    ll m; cin >> n >> m;
    cities.resize(n);
    towers.resize(m);
    for (ll i = 0; i < n; i++) cin >> cities[i];
    for (ll i = 0; i < m; i++) cin >> towers[i];

    sort(towers.begin(), towers.end());

    ll l = 0;
    ll r = 2e9, mid;
    ll ans = 2e9;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}