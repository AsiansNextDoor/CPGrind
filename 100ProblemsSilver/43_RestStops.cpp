#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ll INF;

signed main() {
    IOS;

    ll l, n, rf, rb; cin >> l >> n >> rf >> rb;
    vector<vector<ll>> stops(n, vector<ll>(2));
    for (ll i = 0; i < n; i++) {
        cin >> stops[i][0] >> stops[i][1];
    }

    sort(stops.begin(), stops.end());

    deque<vector<ll>> dq;
    for (ll i = 0; i < n; i++) {
        ll x = stops[i][0], c = stops[i][1];
        while(!dq.empty() && dq.back()[1] < c) dq.pop_back();
        dq.push_back({x, c});
    }

    ll ppos = 0;
    ll ans = 0;
    ll d = rf - rb;
    while (!dq.empty()) {
        ans += (dq.front()[0] - ppos) * d * dq.front()[1];
        ppos = dq.front()[0];
        dq.pop_front();
    }

    cout << ans << endl;
}