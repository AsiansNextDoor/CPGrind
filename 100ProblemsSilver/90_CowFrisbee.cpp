#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF;

signed main() {
    IOS;

    ll n; cin >> n;
    vector<ll> cows(n);
    for (ll i = 0; i < n; i++) cin >> cows[i];

    ll ans = 0, dist = 0;
    stack<vector<ll>> ci; ci.push({cows[0], 0});
    for (ll j = 1; j < n; j++) {
        while (!ci.empty() && ci.top()[0] < cows[j]) {
            ans += j - ci.top()[1] + 1;
            ci.pop();
        }
        if (!ci.empty()) ans += j - ci.top()[1] + 1;
        ci.push({cows[j], j});
    }

    cout << ans << endl;
}