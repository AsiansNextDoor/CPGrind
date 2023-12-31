#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
    ll n, m; cin >> n >> m;

    vector<ll> left, right;
    for (ll i = 0; i < n; i++) {
        ll ai; cin >> ai;
        if (i < n / 2) left.push_back(ai % m);
        else right.push_back(ai % m);
    }

    set<ll> s1, s2;

    for (ll i = 0; i < (1 << left.size()); i++) {
        ll cnt = 0;
        for (ll j = 0; j < left.size(); j++) {
            if ((i >> j) & 1) cnt += left[j];
        }

        s1.insert(cnt % m);
    }
    
    for (ll i = 0; i < (1 << right.size()); i++) {
        ll cnt = 0;
        for (ll j = 0; j < right.size(); j++) {
            if ((i >> j) & 1) cnt += right[j];
        }

        s2.insert(cnt % m);
    }

    ll ans = 0;
    for (ll i: s1) {
        auto it = s2.upper_bound(m - 1 - i);
        if (it != s2.begin()) it--;
        ans = max(*it + i, ans);
    }

    cout << ans << endl;
}