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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n+1); a[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    while (m--) {
        ll b; cin >> b;

        auto it = lower_bound(a.begin(), a.end(), b);
        ll f = it - a.begin();
        it--;
        ll k = b - *it;
        cout << f << " " << k << endl;
    }
}