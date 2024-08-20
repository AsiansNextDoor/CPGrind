#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

signed main() {
    IOS;

    ll n, a, b; cin >> n >> a >> b;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (ll i = 1; i < n; i++) x[i] += x[i - 1];

    multiset<ll> maxsum;
    for (ll i = a - 1; i < b; i++) maxsum.insert(x[i]);

    auto e = maxsum.end(); e--;
    ll ans = *e;
    for (ll i = 1; i + a - 1 < n; i++) {
        maxsum.erase(maxsum.find(x[i + a - 2]));
        if (i + b - 1 < n) maxsum.insert(x[i + b - 1]);
        e = maxsum.end(); e--;
        ans = max(*e - x[i - 1], ans);
    }

    cout << ans << endl;
}