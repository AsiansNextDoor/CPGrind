#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

signed main() {
    IOS;

    ll n, m, r; cin >> n >> m >> r;
    vector<ll> cows(n + 1, 0); // off by one to reflect cows for farmers
    vector<vector<ll>> stores(m, vector<ll>(2));
    vector<ll> farmers(r, 0);
    for (ll i = 1; i <= n; i++) cin >> cows[i];
    for (ll i = 0; i < m; i++) cin >> stores[i][1] >> stores[i][0];
    for (ll i = 0; i < r; i++) cin >> farmers[i];

    sort(cows.begin(), cows.end());
    sort(stores.rbegin(), stores.rend());
    sort(farmers.rbegin(), farmers.rend());


    ll si = 0;
    ll fi = n;
    ll smoney = 0;
    ll fmoney = 0;
    for (ll i = 0; i < n; i++) if (i < r) fmoney += farmers[i];

    ll ans = fmoney;
    while (fi > 0 && si < m) {
        ll milk = cows[fi];
        fi--;
        if (fi < r) fmoney -= farmers[fi];

        while (si < m && stores[si][1] <= milk) {
            smoney += stores[si][0] * stores[si][1];
            milk -= stores[si][1];
            si++;
        }
        if (si < m) {
            smoney += stores[si][0] * milk;
            stores[si][1] -= milk;
        }

        ans = max(smoney + fmoney, ans);
    }

    cout << ans << endl;
}