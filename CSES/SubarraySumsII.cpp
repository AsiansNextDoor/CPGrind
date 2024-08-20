#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

signed main() {
    IOS;

    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> m;
    vector<ll> psum(n + 1, 0);
    for (ll i = 1; i <= n; i++) psum[i] = a[i - 1] + psum[i - 1];
    for (ll i = 0; i <= n; i++) m[psum[i]]++;



    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        m[psum[i]]--;
        ans += m[psum[i] + x];
    }

    cout << ans << endl;
}