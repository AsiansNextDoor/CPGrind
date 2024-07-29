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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll ans = a[0];
    ll cur = 0;
    for (ll i = 0; i < n; i++) {
        cur += a[i];
        if (cur < 0) {
            cur = 0;
            ans = max(a[i], ans);
        }
        else ans = max(cur, ans);
    }

    cout << ans << endl;
}