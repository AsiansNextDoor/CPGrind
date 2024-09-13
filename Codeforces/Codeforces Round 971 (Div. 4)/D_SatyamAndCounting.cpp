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
        
        vector<ll> x(n + 1, 0);
        vector<vector<ll>> y(2);
        vector<vector<ll>> pairs;
        vector<vector<ll>> grid(n + 1, vector<ll>(2, 0));
        for (ll i = 0; i < n; i++) {
            ll x1, y1; cin >> x1 >> y1;
            x[x1] = 1 - x[x1];
            y[y1].push_back(x1);
            pairs.push_back({x1, y1});
            grid[x1][y1]++;
        }

        ll ans = 0;
        for (auto data: pairs) {
            ll x1 = data[0], y1 = data[1];
            if (!x[x1]) ans += y[y1].size() - 1;
            if (x1 <= 0 || x1 >= n) continue;
            if (grid[x1 - 1][1 - y1] && grid[x1 + 1][1 - y1]) ans++;
        }

        cout << ans << endl;
    }
}